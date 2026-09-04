struct SegmentTreeBeats{
	static const long long INF = (1LL << 60);
	struct S{
		long long sum, max1, max2, min1, min2, add;
		int maxc, minc;
	};
	int n;
	vector<S> seg;
	SegmentTreeBeats(vector<long long> a){
		n = a.size();
		seg.resize(n * 4);
		build(1, 0, n, a);
	}
	void build(int k, int l, int r, vector<long long> &a){
		if (r - l == 1){
			seg[k] = {a[l], a[l], -INF, a[l], INF, 0, 1, 1};
			return;
		}
		int m = (l + r) / 2;
		build(k * 2, l, m, a);
		build(k * 2 + 1, m, r, a);
		pull(k);
	}
	void pull(int k){
		S &x = seg[k], &l = seg[k * 2], &r = seg[k * 2 + 1];
		x.sum = l.sum + r.sum;
		x.add = 0;
		if (l.max1 > r.max1){
			x.max1 = l.max1;
			x.maxc = l.maxc;
			x.max2 = max(l.max2, r.max1);
		} else if (l.max1 < r.max1){
			x.max1 = r.max1;
			x.maxc = r.maxc;
			x.max2 = max(l.max1, r.max2);
		} else {
			x.max1 = l.max1;
			x.maxc = l.maxc + r.maxc;
			x.max2 = max(l.max2, r.max2);
		}
		if (l.min1 < r.min1){
			x.min1 = l.min1;
			x.minc = l.minc;
			x.min2 = min(l.min2, r.min1);
		} else if (l.min1 > r.min1){
			x.min1 = r.min1;
			x.minc = r.minc;
			x.min2 = min(l.min1, r.min2);
		} else {
			x.min1 = l.min1;
			x.minc = l.minc + r.minc;
			x.min2 = min(l.min2, r.min2);
		}
	}
	void apply_add(int k, long long x, int len){
		S &s = seg[k];
		s.sum += x * len;
		s.max1 += x;
		if (s.max2 != -INF) s.max2 += x;
		s.min1 += x;
		if (s.min2 != INF) s.min2 += x;
		s.add += x;
	}
	void apply_chmin(int k, long long x){
		S &s = seg[k];
		s.sum += (x - s.max1) * s.maxc;
		if (s.min1 == s.max1) s.min1 = x;
		else if (s.min2 == s.max1) s.min2 = x;
		s.max1 = x;
	}
	void apply_chmax(int k, long long x){
		S &s = seg[k];
		s.sum += (x - s.min1) * s.minc;
		if (s.max1 == s.min1) s.max1 = x;
		else if (s.max2 == s.min1) s.max2 = x;
		s.min1 = x;
	}
	void push(int k, int l, int r){
		if (r - l == 1) return;
		int m = (l + r) / 2;
		if (seg[k].add != 0){
			apply_add(k * 2, seg[k].add, m - l);
			apply_add(k * 2 + 1, seg[k].add, r - m);
			seg[k].add = 0;
		}
		if (seg[k * 2].max1 > seg[k].max1) apply_chmin(k * 2, seg[k].max1);
		if (seg[k * 2 + 1].max1 > seg[k].max1) apply_chmin(k * 2 + 1, seg[k].max1);
		if (seg[k * 2].min1 < seg[k].min1) apply_chmax(k * 2, seg[k].min1);
		if (seg[k * 2 + 1].min1 < seg[k].min1) apply_chmax(k * 2 + 1, seg[k].min1);
	}
	void chmin(int a, int b, long long x){
		chmin(1, 0, n, a, b, x);
	}
	void chmin(int k, int l, int r, int a, int b, long long x){
		if (r <= a || b <= l || seg[k].max1 <= x) return;
		if (a <= l && r <= b && seg[k].max2 < x){
			apply_chmin(k, x);
			return;
		}
		push(k, l, r);
		int m = (l + r) / 2;
		chmin(k * 2, l, m, a, b, x);
		chmin(k * 2 + 1, m, r, a, b, x);
		pull(k);
	}
	void chmax(int a, int b, long long x){
		chmax(1, 0, n, a, b, x);
	}
	void chmax(int k, int l, int r, int a, int b, long long x){
		if (r <= a || b <= l || x <= seg[k].min1) return;
		if (a <= l && r <= b && x < seg[k].min2){
			apply_chmax(k, x);
			return;
		}
		push(k, l, r);
		int m = (l + r) / 2;
		chmax(k * 2, l, m, a, b, x);
		chmax(k * 2 + 1, m, r, a, b, x);
		pull(k);
	}
	void add(int a, int b, long long x){
		add(1, 0, n, a, b, x);
	}
	void add(int k, int l, int r, int a, int b, long long x){
		if (r <= a || b <= l) return;
		if (a <= l && r <= b){
			apply_add(k, x, r - l);
			return;
		}
		push(k, l, r);
		int m = (l + r) / 2;
		add(k * 2, l, m, a, b, x);
		add(k * 2 + 1, m, r, a, b, x);
		pull(k);
	}
	long long sum(int a, int b){
		return sum(1, 0, n, a, b);
	}
	long long sum(int k, int l, int r, int a, int b){
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k].sum;
		push(k, l, r);
		int m = (l + r) / 2;
		return sum(k * 2, l, m, a, b) + sum(k * 2 + 1, m, r, a, b);
	}
};
