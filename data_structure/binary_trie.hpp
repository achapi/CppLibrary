#pragma once

template <class UInt = unsigned, int B = 30> struct binary_trie {
    struct node { std::array<int, 2> ch{-1, -1}; int count = 0; };
    std::vector<node> t{{}};
    void add(UInt x, int delta = 1) {
        int v = 0; t[v].count += delta;
        for (int b = B - 1; b >= 0; --b) {
            int c = x >> b & 1;
            if (t[v].ch[c] == -1) t[v].ch[c] = t.size(), t.push_back({});
            v = t[v].ch[c]; t[v].count += delta;
        }
    }
    int count(UInt x) const {
        int v = 0;
        for (int b = B - 1; b >= 0; --b) { v = t[v].ch[x >> b & 1]; if (v == -1) return 0; }
        return t[v].count;
    }
    UInt min_xor(UInt x) const {
        assert(t[0].count > 0); int v = 0; UInt ans = 0;
        for (int b = B - 1; b >= 0; --b) {
            int c = x >> b & 1, to = t[v].ch[c];
            if (to == -1 || t[to].count == 0) c ^= 1, ans |= UInt(1) << b;
            v = t[v].ch[c];
        }
        return ans;
    }
};
