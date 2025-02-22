vector<vector<vector<int>>> enumerateKPersonGroups(int N, int K) {
	vector<vector<vector<int>>> res;
	vector<vector<int>> g(N / K);
	vector<bool> u(N);
	auto dfs = [&](auto dfs, int i) -> void {
		if (i == N / K) {
			res.push_back(g);
			return;
		}
		int s = (i == 0) ? 0 : g[i - 1][0] + 1;
		vector<int> t;
		auto bt = [&](auto bt, int x) -> void {
			if ((int) t.size() == K) {
				g[i] = t;
				dfs(dfs, i + 1);
				return;
			}
			for (int j = x; j < N; j++) {
				if (!u[j]) {
					u[j] = true;
					t.push_back(j);
					bt(bt, j + 1);
					t.pop_back();
					u[j] = false;
				}
			}
		};
		bt(bt, s);
	};
	dfs(dfs, 0);
	return res;
}
