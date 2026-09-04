struct PointAddRectangleSum {
	struct Op {
		int t, x, y, l, d, r, u;
		long long w;
	};
	vector<Op> q;
	vector<int> xs;
	vector<vector<int>> ys;
	vector<vector<long long>> bit;
	int n;
	void add_point(int x, int y, long long w){
		q.push_back({0, x, y, 0, 0, 0, 0, w});
	}
	void add_query(int l, int d, int r, int u){
		q.push_back({1, 0, 0, l, d, r, u, 0});
	}
	void build(){
		for (int i = 0; i < (int)q.size(); i++){
			if (q[i].t == 0){
				xs.push_back(q[i].x);
			}
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		n = xs.size();
		ys.resize(n + 1);
		for (int k = 0; k < (int)q.size(); k++){
			if (q[k].t == 1){
				continue;
			}
			int p = lower_bound(xs.begin(), xs.end(), q[k].x) - xs.begin() + 1;
			for (int i = p; i <= n; i += i & -i){
				ys[i].push_back(q[k].y);
			}
		}
		bit.resize(n + 1);
		for (int i = 1; i <= n; i++){
			sort(ys[i].begin(), ys[i].end());
			ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
			bit[i].resize(ys[i].size() + 1);
		}
	}
	void add(int x, int y, long long w){
		int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
		for (int i = p; i <= n; i += i & -i){
			int k = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin() + 1;
			for (int j = k; j < (int)bit[i].size(); j += j & -j){
				bit[i][j] += w;
			}
		}
	}
	long long sum(int x, int y){
		long long res = 0;
		int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
		for (int i = p; i > 0; i -= i & -i){
			int k = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
			for (int j = k; j > 0; j -= j & -j){
				res += bit[i][j];
			}
		}
		return res;
	}
	long long sum(int l, int d, int r, int u){
		return sum(r, u) - sum(l, u) - sum(r, d) + sum(l, d);
	}
	vector<long long> solve(){
		build();
		vector<long long> ans;
		for (int i = 0; i < (int)q.size(); i++){
			if (q[i].t == 0){
				add(q[i].x, q[i].y, q[i].w);
			}
			if (q[i].t == 1){
				ans.push_back(sum(q[i].l, q[i].d, q[i].r, q[i].u));
			}
		}
		return ans;
	}
};
