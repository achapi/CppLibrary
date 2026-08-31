#include <bits/stdc++.h>
#include "データ構造/二進トライ木.hpp"
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
int main() { ios::sync_with_stdio(false); cin.tie(nullptr); int q; cin >> q; binary_trie<unsigned, 30> tr; while (q--) { int t; unsigned x; cin >> t >> x; if (t == 0) { if (!tr.count(x)) tr.add(x); } else if (t == 1) { if (tr.count(x)) tr.add(x, -1); } else cout << tr.min_xor(x) << '\n'; } }
