#pragma once

struct lowlink {
    int n, timer = 0;
    vector<vector<pair<int, int>>> g;
    vector<int> ord, low;
    vector<int> articulation;
    vector<int> bridges;
    explicit lowlink(int n) : n(n), g(n), ord(n, -1), low(n) {}
    void add_edge(int u, int v, int id) { g[u].push_back({v, id}); g[v].push_back({u, id}); }
    void dfs(int u, int pe = -1) {
        ord[u] = low[u] = timer++; int child = 0; bool art = false;
        for (auto [v, id] : g[u]) {
            if (id == pe) continue;
            if (ord[v] == -1) {
                ++child; dfs(v, id); low[u] = min(low[u], low[v]);
                if (pe != -1 && ord[u] <= low[v]) art = true;
                if (ord[u] < low[v]) bridges.push_back(id);
            } else low[u] = min(low[u], ord[v]);
        }
        if (pe == -1 && child >= 2) art = true;
        if (art) articulation.push_back(u);
    }
    void build() { for (int i = 0; i < n; ++i) if (ord[i] == -1) dfs(i); }
};
