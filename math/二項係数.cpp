struct Comb {
	vector<mint> f, g;
	Comb(){
		int n = min(mint::mod() - 1, 10000000);
		f.resize(n + 1);
		g.resize(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++){
			f[i] = f[i - 1] * i;
		}
		g[n] = f[n].inv();
		for (int i = n; i; i--){
			g[i - 1] = g[i] * i;
		}
	}
	mint operator()(int n, int k) const {
		return k < 0 or k > n ? 0 : f[n] * g[k] * g[n - k];
	}
};
