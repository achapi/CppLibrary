template<class T> vector<T> Dijkstra(vector<vector<pair<int, T>>> &G, int s){
	vector<T> D(G.size(), 1e18);
	D[s] = 0;
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
	q.push(make_pair(0, s));
	while (!q.empty()){
		auto [d, u] = q.top();
		q.pop();
		if (D[u] < d){
			continue;
		}
		for (auto [v, c] : G[u]){
			d = D[u] + c;
			if (d < D[v]){
				D[v] = d;
				q.push(make_pair(d, v));
			}
		}
	}
	return D;
}
