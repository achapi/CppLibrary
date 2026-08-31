#pragma once

template <class T> using weighted_graph = vector<vector<pair<int, T>>>;

template <class T> pair<vector<T>, vector<int>> dijkstra(const weighted_graph<T>& g, int s) {
    const T inf = numeric_limits<T>::max() / 2;
    vector<T> d(g.size(), inf); vector<int> par(g.size(), -1);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
    d[s] = T{}; pq.emplace(T{}, s);
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop(); if (du != d[u]) continue;
        for (auto [v, w] : g[u]) if (du + w < d[v]) d[v] = du + w, par[v] = u, pq.emplace(d[v], v);
    }
    return {d, par};
}

template <class T> pair<vector<T>, bool> bellman_ford(int n, const vector<tuple<int, int, T>>& es, int s) {
    const T inf = numeric_limits<T>::max() / 2;
    vector<T> d(n, inf); d[s] = T{};
    for (int it = 0; it < n; ++it) {
        bool changed = false;
        for (auto [u, v, w] : es) if (d[u] != inf && d[u] + w < d[v]) d[v] = d[u] + w, changed = true;
        if (!changed) return {d, false};
    }
    return {d, true};
}

template <class T> vector<vector<T>> warshall_floyd(vector<vector<T>> d) {
    const T inf = numeric_limits<T>::max() / 2;
    int n = d.size();
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) if (d[i][k] != inf)
        for (int j = 0; j < n; ++j) if (d[k][j] != inf) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

inline vector<int> restore_path(int t, const vector<int>& par) {
    vector<int> p; for (; t != -1; t = par[t]) p.push_back(t);
    reverse(p.begin(), p.end()); return p;
}
