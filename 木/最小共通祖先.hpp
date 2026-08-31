#pragma once

struct lowest_common_ancestor {
    int n, log;
    std::vector<std::vector<int>> up;
    std::vector<int> depth;
    lowest_common_ancestor(const std::vector<std::vector<int>>& g, int root = 0)
        : n(g.size()), log(std::bit_width((unsigned)g.size())), up(log, std::vector<int>(n, -1)), depth(n) { traverse(g, root); build(); }
    void traverse(const std::vector<std::vector<int>>& g, int root) {
        std::vector<int> st{root};
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            for (int v : g[u]) if (v != up[0][u]) {
                up[0][v] = u; depth[v] = depth[u] + 1; st.push_back(v);
            }
        }
    }
    void build() { for (int k = 1; k < log; ++k) for (int v = 0; v < n; ++v) if (up[k - 1][v] != -1) up[k][v] = up[k - 1][up[k - 1][v]]; }
    int jump(int v, int d) const { for (int k = 0; k < log && v != -1; ++k) if (d >> k & 1) v = up[k][v]; return v; }
    int lca(int u, int v) const {
        if (depth[u] < depth[v]) std::swap(u, v);
        u = jump(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int k = log - 1; k >= 0; --k) if (up[k][u] != up[k][v]) u = up[k][u], v = up[k][v];
        return up[0][u];
    }
    int distance(int u, int v) const { int a = lca(u, v); return depth[u] + depth[v] - 2 * depth[a]; }
};
