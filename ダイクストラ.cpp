vector<long long> Dijkstra(vector<vector<pair<int, long long>>> &G, int s){
	vector<long long> D(G.size(), 1e18);
	D[s] = 0;
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
	q.push(make_pair(0, s));
	while (!q.empty()){
		long long d = q.top().first;
		int u = q.top().second;
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
