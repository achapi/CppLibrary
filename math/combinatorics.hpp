#pragma once

template <class Mint> struct combinatorics {
    vector<Mint> fact{1}, ifact{1};
    combinatorics() = default; explicit combinatorics(int n) { reserve(n); }
    void reserve(int n) { int old = fact.size(); if (old > n) return; fact.resize(n + 1); for (int i = old; i <= n; ++i) fact[i] = fact[i - 1] * i; ifact.resize(n + 1); ifact[n] = fact[n].inv(); for (int i = n; i >= old; --i) ifact[i - 1] = ifact[i] * i; }
    Mint factorial(int n) { reserve(n); return fact[n]; }
    Mint binom(int n, int k) { if (k < 0 || k > n) return 0; reserve(n); return fact[n] * ifact[k] * ifact[n - k]; }
    Mint perm(int n, int k) { if (k < 0 || k > n) return 0; reserve(n); return fact[n] * ifact[n - k]; }
};
