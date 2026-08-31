template <class S, S (*op)(S, S), S (*e)()>
struct SparseTable {
	int n, LOG;
	vector<vector<S>> st;
	SparseTable() {}
	SparseTable(const vector<S>& v) { build(v); }
	void build(const vector<S>& v) {
		n = (int)v.size();
		LOG = 32 - __builtin_clz(n);
		st.assign(LOG, vector<S>(n));
		st[0] = v;
		for (int k = 1; k < LOG; k++) {
			for (int i = 0; i + (1 << k) <= n; i++) {
				st[k][i] = op(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
			}
		}
	}
	S prod(int l, int r) const {
		if (l >= r) return e();
		int k = 31 - __builtin_clz(r - l);
		return op(st[k][l], st[k][r - (1 << k)]);
	}
};
