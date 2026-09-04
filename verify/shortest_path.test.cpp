#include <bits/stdc++.h>
using namespace std;
#include "graph/最短経路.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	weighted_graph<long long> g(n);
	while (m--){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}
	auto [d, p] = dijkstra(g, s);
	if (d[t] >= numeric_limits<long long>::max() / 2){
		cout << -1 << endl;
		return 0;
	}
	auto path = restore_path(t, p);
	cout << d[t] << ' ' << path.size() - 1 << endl;
	for (int i = 1; i < (int)path.size(); ++i){
		cout << path[i - 1] << ' ' << path[i] << endl;
	}
}
