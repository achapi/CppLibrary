#pragma once

template <class T> using weighted_graph = std::vector<std::vector<std::pair<int, T>>>;

template <class T> std::pair<std::vector<T>, std::vector<int>> dijkstra(const weighted_graph<T>& g, int s) {
    const T inf = std::numeric_limits<T>::max() / 2;
    std::vector<T> d(g.size(), inf); std::vector<int> par(g.size(), -1);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> pq;
    d[s] = T{}; pq.emplace(T{}, s);
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop(); if (du != d[u]) continue;
        for (auto [v, w] : g[u]) if (du + w < d[v]) d[v] = du + w, par[v] = u, pq.emplace(d[v], v);
    }
    return {d, par};
}

template <class T> std::pair<std::vector<T>, bool> bellman_ford(int n, const std::vector<std::tuple<int, int, T>>& es, int s) {
    const T inf = std::numeric_limits<T>::max() / 2;
    std::vector<T> d(n, inf); d[s] = T{};
    for (int it = 0; it < n; ++it) {
        bool changed = false;
        for (auto [u, v, w] : es) if (d[u] != inf && d[u] + w < d[v]) d[v] = d[u] + w, changed = true;
        if (!changed) return {d, false};
    }
    return {d, true};
}

template <class T> std::vector<std::vector<T>> warshall_floyd(std::vector<std::vector<T>> d) {
    const T inf = std::numeric_limits<T>::max() / 2;
    int n = d.size();
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) if (d[i][k] != inf)
        for (int j = 0; j < n; ++j) if (d[k][j] != inf) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

inline std::vector<int> restore_path(int t, const std::vector<int>& par) {
    std::vector<int> p; for (; t != -1; t = par[t]) p.push_back(t);
    std::reverse(p.begin(), p.end()); return p;
}
