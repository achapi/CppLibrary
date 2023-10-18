template<class T> vector<T> Dijkstra(vector<vector<pair<int, T>>> &G, int s){
	vector<T> D(G.size(), 1e18);
	D[s] = 0;
	priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> q;
	q.push(make_pair(0, s));
	while (!q.empty()){
		auto [u, d] = q.top();
		q.pop();
		if (D[u] < d){
			continue;
		}
		for (auto [v, c] : G[u]){
			d = D[u] + c;
			if (d < D[v]){
				D[v] = d;
				q.push(make_pair(v, d));
			}
		}
	}
	return D;
}
