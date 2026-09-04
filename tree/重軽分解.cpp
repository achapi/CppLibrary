struct heavy_light_decomposition {
	int n, timer = 0;
	vector<vector<int>> g;
	vector<int> parent, depth, size, head, in, out, rev;
	explicit heavy_light_decomposition(vector<vector<int>> g, int root = 0)
		: n(g.size()), g(move(g)), parent(n, -1), depth(n), size(n), head(n), in(n), out(n),
		  rev(n){
		dfs_size(root);
		head[root] = root;
		dfs_hld(root);
	}
	void dfs_size(int u){
		size[u] = 1;
		int heavy = -1;
		for (int v : g[u]){
			if (v != parent[u]){
				parent[v] = u;
				depth[v] = depth[u] + 1;
				dfs_size(v);
				size[u] += size[v];
				if (heavy == -1 or size[v] > size[heavy]){
					heavy = v;
				}
			}
		}
		if (heavy != -1){
			iter_swap(g[u].begin(), find(g[u].begin(), g[u].end(), heavy));
		}
	}
	void dfs_hld(int u){
		in[u] = timer;
		rev[timer++] = u;
		bool first = true;
		for (int v : g[u]){
			if (v != parent[u]){
				head[v] = first ? head[u] : v;
				first = false;
				dfs_hld(v);
			}
		}
		out[u] = timer;
	}
	int lca(int u, int v) const {
		while (head[u] != head[v]){
			if (in[head[u]] < in[head[v]]){
				swap(u, v);
			}
			u = parent[head[u]];
		}
		return in[u] < in[v] ? u : v;
	}
	template <class F> void path_query(int u, int v, F f, bool edge = false) const {
		while (head[u] != head[v]){
			if (in[head[u]] < in[head[v]]){
				swap(u, v);
			}
			f(in[head[u]], in[u] + 1);
			u = parent[head[u]];
		}
		if (in[u] > in[v]){
			swap(u, v);
		}
		f(in[u] + edge, in[v] + 1);
	}
	pair<int, int> subtree(int u, bool edge = false) const {
		return {in[u] + edge, out[u]};
	}
};
