struct CycleDetection{
	int N;
	vector<vector<int>> G;
	vector<pair<int, int>> E;
	vector<int> state, par, ans;
	CycleDetection(int N) : N(N), G(N), state(N), par(N, -1){}
	void add_edge(int u, int v){
		G[u].push_back(E.size());
		E.push_back({u, v});
	}
	bool dfs(int v){
		state[v] = 1;
		for (int e : G[v]){
			int u = E[e].second;
			if (state[u] == 0){
				par[u] = e;
				if (dfs(u)) return true;
			}
			if (state[u] == 1){
				ans.push_back(e);
				int x = v;
				while (x != u){
					ans.push_back(par[x]);
					x = E[par[x]].first;
				}
				reverse(ans.begin(), ans.end());
				return true;
			}
		}
		state[v] = 2;
		return false;
	}
	vector<int> solve(){
		for (int i = 0; i < N; i++){
			if (state[i] == 0 && dfs(i)) return ans;
		}
		return {};
	}
};
