#pragma once

template <class T> pair<T, vector<int>> kruskal(int n, const vector<tuple<T, int, int>>& edges) {
    vector<int> ord(edges.size()); for (int i = 0; i < (int)ord.size(); ++i) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return get<0>(edges[i]) < get<0>(edges[j]); });
    atcoder::dsu uf(n); T cost{}; vector<int> used;
    for (int i : ord) { auto [w, u, v] = edges[i]; if (!uf.same(u, v)) uf.merge(u, v), cost += w, used.push_back(i); }
    return {cost, used};
}
