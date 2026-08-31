#pragma once

template <class F, F (*composition)(F, F), F (*id)()> struct dual_segtree {
    int size, log;
    vector<F> lazy;
    explicit dual_segtree(int n) : size(1), log(0) {
        while (size < n) size <<= 1, ++log;
        lazy.assign(2 * size, id());
    }
    void all_apply(int k, F f) { lazy[k] = composition(f, lazy[k]); }
    void push(int k) { all_apply(2 * k, lazy[k]); all_apply(2 * k + 1, lazy[k]); lazy[k] = id(); }
    void apply(int l, int r, F f) {
        l += size; r += size;
        for (int i = log; i; --i) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); }
        while (l < r) { if (l & 1) all_apply(l++, f); if (r & 1) all_apply(--r, f); l >>= 1; r >>= 1; }
    }
    F get(int p) { p += size; for (int i = log; i; --i) push(p >> i); return lazy[p]; }
};
