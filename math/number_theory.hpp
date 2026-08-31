#pragma once

namespace number_theory {
using u64 = std::uint64_t; using u128 = __uint128_t;
inline u64 mul_mod(u64 a, u64 b, u64 m) { return u128(a) * b % m; }
inline u64 pow_mod(u64 a, u64 n, u64 m) { u64 r = 1 % m; for (; n; n >>= 1, a = mul_mod(a, a, m)) if (n & 1) r = mul_mod(r, a, m); return r; }
inline bool is_prime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { if (n % p == 0) return n == p; }
    int s = std::countr_zero(n - 1); u64 d = (n - 1) >> s;
    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true; for (int r = 1; r < s; ++r) { x = mul_mod(x, x, n); if (x == n - 1) { comp = false; break; } }
        if (comp) return false;
    }
    return true;
}
inline u64 pollard_rho(u64 n) {
    if (!(n & 1)) return 2;
    static std::mt19937_64 rng(std::random_device{}());
    for (;;) { u64 c = rng() % (n - 1) + 1, x = rng() % n, y = x, d = 1;
        auto f = [&](u64 v) { return (mul_mod(v, v, n) + c) % n; };
        while (d == 1) x = f(x), y = f(f(y)), d = std::gcd(x > y ? x - y : y - x, n);
        if (d != n) return d;
    }
}
inline void factor_rec(u64 n, std::vector<u64>& f) { if (n == 1) return; if (is_prime(n)) { f.push_back(n); return; } u64 d = pollard_rho(n); factor_rec(d, f); factor_rec(n / d, f); }
inline std::vector<u64> factorize(u64 n) { std::vector<u64> f; factor_rec(n, f); std::sort(f.begin(), f.end()); return f; }
inline std::vector<int> primes(int n) {
    std::vector<int> lp(n + 1), ps; for (int i = 2; i <= n; ++i) { if (!lp[i]) lp[i] = i, ps.push_back(i); for (int p : ps) { if (p > lp[i] || 1LL * i * p > n) break; lp[i * p] = p; } } return ps;
}
inline long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0; if (a < 0) { long long q = (a - m + 1) / m; ans += n * (n - 1) / 2 * q; a -= q * m; } if (b < 0) { long long q = (b - m + 1) / m; ans += n * q; b -= q * m; }
    while (true) { if (a >= m) ans += n * (n - 1) / 2 * (a / m), a %= m; if (b >= m) ans += n * (b / m), b %= m; long long y = a * n + b; if (y < m) break; n = y / m; b = y % m; std::swap(m, a); } return ans;
}
} // namespace number_theory
