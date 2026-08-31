struct Lowest_Common_Ancestor {
	vector<vector<int>> parent;
	vector<int> dist;
	Lowest_Common_Ancestor(const vector<vector<int>> &G, int root = 0) { init(G, root); }
	void init(const vector<vector<int>> &G, int root = 0) {
		int V = G.size();
		int K = 1;
		while ((1 << K) < V) K++;
		parent.assign(K, vector<int>(V, -1));
		dist.assign(V, -1);
		dfs(G, root, -1, 0);
		for (int k = 0; k + 1 < K; k++) {
			for (int v = 0; v < V; v++) {
				if (parent[k][v] < 0) {
					parent[k + 1][v] = -1;
				} else {
					parent[k + 1][v] = parent[k][parent[k][v]];
				}
			}
		}
	}
	void dfs(const vector<vector<int>> &G, int v, int p, int d) {
		parent[0][v] = p;
		dist[v] = d;
		for (auto e : G[v]) {
			if (e != p) dfs(G, e, v, d + 1);
		}
	}
	int query(int u, int v) {
		if (dist[u] < dist[v]) swap(u, v);
		int K = parent.size();
		for (int k = 0; k < K; k++) {
			if ((dist[u] - dist[v]) >> k & 1) {
				u = parent[k][u];
			}
		}
		if (u == v) return u;
		for (int k = K - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	int get_dist(int u, int v) {
		return dist[u] + dist[v] - 2 * dist[query(u, v)];
	}
	bool is_on_path(int u, int v, int a) {
		return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
	}
};
