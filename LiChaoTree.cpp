struct LiChaoTree{
	struct Line{
		long long a, b;
		long long get(long long x){
			return a * x + b;
		}
	};
	int n;
	vector<long long> x;
	vector<Line> seg;
	LiChaoTree(vector<long long> x) : x(x){
		n = x.size();
		seg.assign(n * 4, {0, INF});
	}
	void add_line(int k, int l, int r, Line f){
		int m = (l + r) / 2;
		bool lef = f.get(x[l]) < seg[k].get(x[l]);
		bool mid = f.get(x[m]) < seg[k].get(x[m]);
		if (mid) swap(f, seg[k]);
		if (r - l == 1) return;
		if (lef != mid) add_line(k * 2, l, m, f);
		else add_line(k * 2 + 1, m, r, f);
	}
	void add_segment(int k, int l, int r, int a, int b, Line f){
		if (r <= a || b <= l) return;
		if (a <= l && r <= b){
			add_line(k, l, r, f);
			return;
		}
		int m = (l + r) / 2;
		add_segment(k * 2, l, m, a, b, f);
		add_segment(k * 2 + 1, m, r, a, b, f);
	}
	void add_segment(long long l, long long r, long long a, long long b){
		int L = lower_bound(x.begin(), x.end(), l) - x.begin();
		int R = lower_bound(x.begin(), x.end(), r) - x.begin();
		if (L < R) add_segment(1, 0, n, L, R, {a, b});
	}
	long long get(long long p){
		int P = lower_bound(x.begin(), x.end(), p) - x.begin();
		int k = 1, l = 0, r = n;
		long long ans = INF;
		while (true){
			ans = min(ans, seg[k].get(p));
			if (r - l == 1) break;
			int m = (l + r) / 2;
			if (P < m){
				k = k * 2;
				r = m;
			} else {
				k = k * 2 + 1;
				l = m;
			}
		}
		return ans;
	}
};
struct Query{
	int t;
	long long l, r, a, b, p;
};
