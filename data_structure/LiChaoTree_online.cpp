struct Line {
	long long a, b;
	long long get(long long x){
		return a * x + b;
	}
};
struct LiChaoTree {
	static const long long INF = (1LL << 62);
	static const long long L = -1000000000;
	static const long long R = 1000000001;
	struct Node {
		Line f = {0, INF};
		int l = -1, r = -1;
	};
	vector<Node> tr;
	LiChaoTree(){
		tr.push_back(Node());
	}
	void add_line(Line f){
		add_line(0, L, R, f);
	}
	void add_line(int k, long long l, long long r, Line f){
		long long m = (l + r) / 2;
		bool lef = f.get(l) < tr[k].f.get(l);
		bool mid = f.get(m) < tr[k].f.get(m);
		if (mid){
			swap(f, tr[k].f);
		}
		if (r - l == 1){
			return;
		}
		if (lef != mid){
			if (tr[k].l == -1){
				tr[k].l = tr.size();
				tr.push_back(Node());
			}
			add_line(tr[k].l, l, m, f);
		} else {
			if (tr[k].r == -1){
				tr[k].r = tr.size();
				tr.push_back(Node());
			}
			add_line(tr[k].r, m, r, f);
		}
	}
	long long get(long long x){
		return get(0, L, R, x);
	}
	long long get(int k, long long l, long long r, long long x){
		long long res = tr[k].f.get(x);
		if (r - l == 1){
			return res;
		}
		long long m = (l + r) / 2;
		if (x < m){
			if (tr[k].l == -1){
				return res;
			}
			return min(res, get(tr[k].l, l, m, x));
		}
		if (tr[k].r == -1){
			return res;
		}
		return min(res, get(tr[k].r, m, r, x));
	}
};
