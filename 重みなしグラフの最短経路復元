vector<int> shortestPath(vector<vector<int>> &G, int s, int g) {
	int N = G.size();
	vector<int> dist(N, -1), parent(N, -1);
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : G[v]) {
			if (dist[u] != -1) continue;
			dist[u] = dist[v] + 1;
			parent[u] = v;
			q.push(u);
		}
	}
	if (dist[g] == -1) return {};
	vector<int> path;
	for (int v = g; v != -1; v = parent[v]) {
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	return path;
}
