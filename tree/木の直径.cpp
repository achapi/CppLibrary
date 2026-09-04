template <class T>
tuple<T, int, int, vector<int>> tree_diameter(const vector<vector<pair<int, T>>>& g){
	auto farthest = [&](int s){
		vector<T> d(g.size(), T(-1));
		vector<int> par(g.size(), -1), st{s};
		d[s] = T{};
		while (!st.empty()){
			int u = st.back();
			st.pop_back();
			for (auto [v, w] : g[u]){
				if (d[v] == T(-1)){
					d[v] = d[u] + w, par[v] = u, st.push_back(v);
				}
			}
		}
		int v = max_element(d.begin(), d.end()) - d.begin();
		return tuple{v, d[v], par};
	};
	auto [s, ignore, p0] = farthest(0);
	auto [t, dist, par] = farthest(s);
	vector<int> path;
	for (int v = t; v != -1; v = par[v]){
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	return {dist, s, t, path};
}
