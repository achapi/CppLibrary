void Dijkstra(const Graph& graph, vector<long long>& distances, int startIndex){
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);
	while (!q.empty()){
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();
		if (distances[from] < distance)continue;
		for (const auto& edge : graph[from]){
			const long long d = (distances[from] + edge.cost);
			if (d < distances[edge.to]){
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}
