#include <bits/stdc++.h>
#include "math/number_theory.hpp"
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
int main() { ios::sync_with_stdio(false); cin.tie(nullptr); int q; cin >> q; while (q--) { uint64_t n; cin >> n; auto f = number_theory::factorize(n); cout << f.size(); for (auto p : f) cout << ' ' << p; cout << '\n'; } }
