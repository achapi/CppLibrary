vector<pair<long long, long long>> convex_hull(vector<pair<long long, long long>> p){
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	int n = p.size();
	if (n <= 2){
		return p;
	}
	auto cross = [](pair<long long, long long> a, pair<long long, long long> b,
					pair<long long, long long> c){
		return (__int128)(b.first - a.first) * (c.second - a.second) -
			   (__int128)(b.second - a.second) * (c.first - a.first);
	};
	vector<pair<long long, long long>> q;
	for (int t = 0; t < 2; t++){
		int s = q.size();
		for (int i = 0; i < n; i++){
			while ((int)q.size() >= s + 2 and cross(q[q.size() - 2], q.back(), p[i]) <= 0){
				q.pop_back();
			}
			q.push_back(p[i]);
		}
		q.pop_back();
		reverse(p.begin(), p.end());
	}
	return q;
}
