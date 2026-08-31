#include <bits/stdc++.h>
#include "数学/整数論.hpp"
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
int main() { ios::sync_with_stdio(false); cin.tie(nullptr); int q; cin >> q; while (q--) { uint64_t n; cin >> n; cout << (number_theory::is_prime(n) ? "Yes" : "No") << '\n'; } }
