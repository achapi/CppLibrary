#include <bits/stdc++.h>
#include "グラフ/最短経路.hpp"
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
int main() { ios::sync_with_stdio(false); cin.tie(nullptr); int n, m, s, t; cin >> n >> m >> s >> t; weighted_graph<long long> g(n); while (m--) { int a, b; long long c; cin >> a >> b >> c; g[a].push_back({b, c}); } auto [d, p] = dijkstra(g, s); if (d[t] >= numeric_limits<long long>::max() / 2) return cout << -1 << '\n', 0; auto path = restore_path(t, p); cout << d[t] << ' ' << path.size() - 1 << '\n'; for (int i = 1; i < (int)path.size(); ++i) cout << path[i - 1] << ' ' << path[i] << '\n'; }
