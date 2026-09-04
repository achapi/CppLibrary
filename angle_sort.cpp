void angle_sort(vector<int> &x, vector<int> &y){
	vector<pair<int, int>> p(x.size());
	for (int i = 0; i < (int) x.size(); i++) p[i] = {x[i], y[i]};
	auto f = [](pair<int, int> p){
		if (p.first == 0 && p.second == 0) return 1;
		if (p.second < 0) return 0;
		if (p.second == 0 && p.first > 0) return 1;
		if (p.second > 0) return 2;
		return 3;
	};
	sort(p.begin(), p.end(), [&](auto a, auto b){
		if (f(a) != f(b)) return f(a) < f(b);
		return (__int128) a.first * b.second > (__int128) a.second * b.first;
	});
	for (int i = 0; i < (int) x.size(); i++) x[i] = p[i].first, y[i] = p[i].second;
}
