struct mo_algorithm {
	int n;
	vector<pair<int, int>> query;
	explicit mo_algorithm(int n) : n(n){}
	void add_query(int l, int r){
		query.emplace_back(l, r);
	}
	template <class AL, class AR, class EL, class ER, class OUT>
	void run(AL add_left, AR add_right, EL erase_left, ER erase_right, OUT out) const {
		int q = query.size(), block = max(1, int(n / max(1.0, sqrt(double(q)))));
		vector<int> ord(q);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int i, int j){
			int a = query[i].first / block, b = query[j].first / block;
			return a != b ? a < b
						  : ((a & 1) ? query[i].second > query[j].second
									 : query[i].second < query[j].second);
		});
		int l = 0, r = 0;
		for (int i : ord){
			auto [ql, qr] = query[i];
			while (l > ql){
				add_left(--l);
			}
			while (r < qr){
				add_right(r++);
			}
			while (l < ql){
				erase_left(l++);
			}
			while (r > qr){
				erase_right(--r);
			}
			out(i);
		}
	}
};
