bool Bellman_ford(const Graph& graph, vector<long long>& distances, int startIndex){
	struct BellmanEdge {
		int from;
		int to;
		long long cost;
	};
	vector<BellmanEdge> Edges;
	for (int v = 0; v < (int) graph.size(); v++){
		for (auto e : graph[v]){
			Edges.push_back({v, e.to, e.cost});
		}
	}
	int V = graph.size();
	const long long INF = (long long) 1 << 60;
	distances.resize(V, INF);
	distances[startIndex] = 0;
	int c = 0;
	while (c < V){
		bool end = true;
		for (auto e : Edges) {
			if (distances[e.from] != INF and distances[e.from] + e.cost < distances[e.to]) {
				distances[e.to] = distances[e.from] + e.cost;
				end = false;
			}
		}
		if (end){
			break;
		}
		c++;
	}
	return (c == V);
}
