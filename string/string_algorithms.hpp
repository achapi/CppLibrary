#pragma once

template <class Seq> std::vector<int> z_algorithm(const Seq& s) {
    int n = s.size(); std::vector<int> z(n); if (!n) return z; z[0] = n;
    for (int i = 1, j = 0; i < n;) { while (i + j < n && s[j] == s[i + j]) ++j; z[i] = j; if (!j) { ++i; continue; } int k = 1; while (i + k < n && k + z[k] < j) z[i + k] = z[k], ++k; i += k; j -= k; }
    return z;
}
template <class Seq> std::vector<int> prefix_function(const Seq& s) {
    std::vector<int> p(s.size()); for (int i = 1; i < (int)s.size(); ++i) { int j = p[i - 1]; while (j && s[i] != s[j]) j = p[j - 1]; if (s[i] == s[j]) ++j; p[i] = j; } return p;
}
template <class Seq> std::vector<int> manacher_odd(const Seq& s) {
    int n = s.size(); std::vector<int> d(n); for (int i = 0, l = 0, r = -1; i < n; ++i) { int k = i > r ? 1 : std::min(d[l + r - i], r - i + 1); while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k; d[i] = k--; if (i + k > r) l = i - k, r = i + k; } return d;
}
inline std::vector<int> enumerate_palindromes(const std::string& s) {
    int n = s.size(); if (!n) return {}; std::vector<int> t(2 * n - 1);
    for (int i = 0; i < n; ++i) t[2 * i] = (unsigned char)s[i] + 1;
    auto d = manacher_odd(t); std::vector<int> a(d.size());
    for (int i = 0; i < (int)a.size(); ++i) a[i] = (i & 1) ? 2 * (d[i] / 2) : 2 * ((d[i] - 1) / 2) + 1;
    return a;
}
