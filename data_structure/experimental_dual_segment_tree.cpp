template<typename T> struct DualSegTree {
	int n;
	vector<T> lazy;
	vector<T> base;
	DualSegTree(int _n) : DualSegTree(vector<T>(_n, T())) {}
	template<typename U>
	DualSegTree(const vector<U>& v) {
		int sz = v.size();
		n = 1;
		while (n < sz) n <<= 1;
		lazy.assign(2 * n, T());
		base.resize(n, T());
		for (int i = 0; i < sz; i++) {
			base[i] = static_cast<T>(v[i]);
		}
	}
	void apply(int l, int r, T val) {
		l += n;
		r += n;
		while (l < r) {
			if (l & 1) lazy[l++] += val;
			if (r & 1) lazy[--r] += val;
			l >>= 1;
			r >>= 1;
		}
	}
	T get(int p) {
		T res = base[p];
		p += n;
		while (p > 0) {
			res += lazy[p];
			p >>= 1;
		}
		return res;
	}
};
