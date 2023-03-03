vector<int>TopologicalSort(const vector<vector<int>>& graph){
	vector<int> indegrees(graph.size());
	for(const auto& v:graph){
		for(const auto& to:v)indegrees[to]++;
	}
	//辞書順最大 → greater<int>を消す
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<(int)graph.size();i++){
		if(indegrees[i]==0)pq.push(i);
	}
	vector<int> result;
	while (!pq.empty()){
		const int from=pq.top();pq.pop();
		result.push_back(from);
		for (const auto& to:graph[from]){
			if(--indegrees[to]==0)pq.push(to);
		}
	}
	if(result.size()!=graph.size())return{};
	return result;
}
