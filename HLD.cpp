struct HLD {
	vector<vector<int>>& g;
	int n;
	vector<int> p, d, s, h, a, in, out, r;
	HLD(vector<vector<int>>& g) : g(g), n(g.size()), p(n, -1), d(n), s(n, 1), h(n, -1), a(n), in(n), out(n), r(n) {}
	void build(int rt = 0){
		vector<int> q(n);
		int z = 0;
		q[z++] = rt;
		for (int i = 0; i < z; i++){
			int v = q[i];
			for (int u : g[v]){
				if (u == p[v]) continue;
				p[u] = v;
				d[u] = d[v] + 1;
				q[z++] = u;
			}
		}
		for (int i = n - 1; i; i--){
			int v = q[i], u = p[v];
			s[u] += s[v];
			if (h[u] == -1 || s[v] > s[h[u]]) h[u] = v;
		}
		int t = 0;
		vector<pair<int, int>> st = {{rt, rt}};
		while (st.size()){
			auto [v, x] = st.back();
			st.pop_back();
			for (int u = v;; u = h[u]){
				a[u] = x;
				in[u] = t;
				r[t++] = u;
				for (int w : g[u]){
					if (w == p[u] || w == h[u]) continue;
					st.push_back({w, w});
				}
				if (h[u] == -1) break;
			}
		}
		for (int i = n - 1; i >= 0; i--) out[q[i]] = in[q[i]] + s[q[i]];
	}
	int lca(int u, int v){
		while (a[u] != a[v]){
			if (d[a[u]] < d[a[v]]) swap(u, v);
			u = p[a[u]];
		}
		return d[u] < d[v] ? u : v;
	}
	int anc(int v, int k){
		int x = d[v] - k;
		if (x < 0) return -1;
		while (d[a[v]] > x) v = p[a[v]];
		return r[in[v] - d[v] + x];
	}
	int jump(int u, int v, int k){
		int w = lca(u, v);
		int x = d[u] - d[w], y = d[v] - d[w];
		if (k > x + y) return -1;
		if (k <= x) return anc(u, k);
		return anc(v, x + y - k);
	}
	int dist(int u, int v){
		int w = lca(u, v);
		return d[u] + d[v] - 2 * d[w];
	}
	pair<int, int> subtree(int v){
		return {in[v], out[v]};
	}
	template<class F> void path(int u, int v, F f){
		vector<array<int, 3>> x, y;
		while (a[u] != a[v]){
			if (d[a[u]] > d[a[v]]){
				x.push_back({in[a[u]], in[u] + 1, 1});
				u = p[a[u]];
			} else {
				y.push_back({in[a[v]], in[v] + 1, 0});
				v = p[a[v]];
			}
		}
		if (d[u] > d[v]) x.push_back({in[v], in[u] + 1, 1});
		else y.push_back({in[u], in[v] + 1, 0});
		for (auto [l, r, z] : x) f(l, r, z);
		reverse(y.begin(), y.end());
		for (auto [l, r, z] : y) f(l, r, z);
	}
};
