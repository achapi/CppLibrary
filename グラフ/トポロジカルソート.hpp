#pragma once

inline std::vector<int> topological_sort(const std::vector<std::vector<int>>& g) {
    std::vector<int> deg(g.size()); for (auto& es : g) for (int v : es) ++deg[v];
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for (int i = 0; i < (int)g.size(); ++i) if (!deg[i]) q.push(i);
    std::vector<int> ord;
    while (!q.empty()) { int u = q.top(); q.pop(); ord.push_back(u); for (int v : g[u]) if (!--deg[v]) q.push(v); }
    if (ord.size() != g.size()) ord.clear();
    return ord;
}
