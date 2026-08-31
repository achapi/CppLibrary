#include <bits/stdc++.h>
using namespace std;
#include "tree/lowest_common_ancestor.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
int main() { ios::sync_with_stdio(false); cin.tie(nullptr); int n, q; cin >> n >> q; vector<vector<int>> g(n); for (int v = 1, p; v < n; ++v) { cin >> p; g[p].push_back(v); g[v].push_back(p); } lowest_common_ancestor lca(g); while (q--) { int u, v; cin >> u >> v; cout << lca.lca(u, v) << '\n'; } }
