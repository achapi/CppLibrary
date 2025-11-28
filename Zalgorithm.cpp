vector<int> TopologicalSort(const vector<vector<int>>& G, int k = -1){
	int N = G.size();
	vector<int> in(N);
	for (int i = 0; i < N; i++) {
		for (int to : G[i]) {
			in[to]++;
		}
	}
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		if (in[i] == 0) {
			pq.push(i * k);
		}
	}
	vector<int> r;
	while (!pq.empty()) {
		int v = pq.top();
		pq.pop();
		r.push_back(v * k);
		for (int to : G[v * k]) {
			in[to]--;
			if (in[to] == 0) {
				pq.push(to * k);
			}
		}
	}
	return (int) r.size() == N ? r : vector<int>();
}
