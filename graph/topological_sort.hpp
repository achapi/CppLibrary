#pragma once

inline vector<int> topological_sort(const vector<vector<int>>& g) {
    vector<int> deg(g.size()); for (auto& es : g) for (int v : es) ++deg[v];
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < (int)g.size(); ++i) if (!deg[i]) q.push(i);
    vector<int> ord;
    while (!q.empty()) { int u = q.top(); q.pop(); ord.push_back(u); for (int v : g[u]) if (!--deg[v]) q.push(v); }
    if (ord.size() != g.size()) ord.clear();
    return ord;
}
