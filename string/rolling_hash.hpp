#pragma once

struct rolling_hash {
    using u64 = uint64_t; static constexpr u64 mod = (u64(1) << 61) - 1;
    u64 base; vector<u64> hash, power;
    static u64 add(u64 a, u64 b) { a += b; return a >= mod ? a - mod : a; }
    static u64 mul(u64 a, u64 b) { __uint128_t c = (__uint128_t)a * b; u64 x = u64(c >> 61) + (u64(c) & mod); return x >= mod ? x - mod : x; }
    explicit rolling_hash(const string& s, u64 b = 0) {
        base = b ? b : 1000000007 + chrono::steady_clock::now().time_since_epoch().count() % 1000000000;
        hash.assign(s.size() + 1, 0); power.assign(s.size() + 1, 1);
        for (int i = 0; i < (int)s.size(); ++i) hash[i + 1] = add(mul(hash[i], base), (unsigned char)s[i] + 1), power[i + 1] = mul(power[i], base);
    }
    u64 get(int l, int r) const { u64 x = hash[r] + mod - mul(hash[l], power[r - l]); return x >= mod ? x - mod : x; }
};
