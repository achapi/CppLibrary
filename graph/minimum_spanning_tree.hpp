#pragma once

template <class T> std::pair<T, std::vector<int>> kruskal(int n, const std::vector<std::tuple<T, int, int>>& edges) {
    std::vector<int> ord(edges.size()); for (int i = 0; i < (int)ord.size(); ++i) ord[i] = i;
    std::sort(ord.begin(), ord.end(), [&](int i, int j) { return std::get<0>(edges[i]) < std::get<0>(edges[j]); });
    atcoder::dsu uf(n); T cost{}; std::vector<int> used;
    for (int i : ord) { auto [w, u, v] = edges[i]; if (!uf.same(u, v)) uf.merge(u, v), cost += w, used.push_back(i); }
    return {cost, used};
}
