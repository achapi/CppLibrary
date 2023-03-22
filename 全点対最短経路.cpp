template<class T>void warshall_floyd(vector<vector<T>> &G) {
	int n = G.size();
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}
