template<typename T> vector<T> TopologicalSort(const vector<vector<T>>& g, bool rev = false) {
	T n = g.size();
	vector<int> in(n);
	for (auto& v : g) for (T to : v) in[to]++;
	priority_queue<T> p1;
	priority_queue<T, vector<T>, greater<T>> p2;
	auto* q = rev ? (priority_queue<T>*)&p1 : (priority_queue<T>*)&p2;
	for (T i = 0; i < n; i++) if (!in[i]) q->push(i);
	vector<T> r;
	while (!q->empty()) {
		T v = q->top(); q->pop();
		r.push_back(v);
		for (T to : g[v]) if (--in[to] == 0) q->push(to);
	}
	return (int) r.size() == n ? r : vector<T>();
}
