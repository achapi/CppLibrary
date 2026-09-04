template <class T, T (*op)(T, T)> struct sparse_table {
	vector<vector<T>> st;
	explicit sparse_table(const vector<T>& a){
		int n = (int)a.size(), lg = n ? bit_width((unsigned)n) : 0;
		st.assign(lg, vector<T>(n));
		if (n){
			st[0] = a;
		}
		for (int k = 1; k < lg; ++k){
			for (int i = 0; i + (1 << k) <= n; ++i){
				st[k][i] = op(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
			}
		}
	}
	T prod(int l, int r) const {
		int k = bit_width((unsigned)(r - l)) - 1;
		return op(st[k][l], st[k][r - (1 << k)]);
	}
};
