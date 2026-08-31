#pragma once

template <class T> std::tuple<T, int, int, std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<int, T>>>& g) {
    auto farthest = [&](int s) {
        std::vector<T> d(g.size(), T(-1)); std::vector<int> par(g.size(), -1), st{s}; d[s] = T{};
        while (!st.empty()) { int u = st.back(); st.pop_back(); for (auto [v, w] : g[u]) if (d[v] == T(-1)) d[v] = d[u] + w, par[v] = u, st.push_back(v); }
        int v = std::max_element(d.begin(), d.end()) - d.begin(); return std::tuple{v, d[v], par};
    };
    auto [s, ignore, p0] = farthest(0); auto [t, dist, par] = farthest(s);
    std::vector<int> path; for (int v = t; v != -1; v = par[v]) path.push_back(v); std::reverse(path.begin(), path.end());
    return {dist, s, t, path};
}
