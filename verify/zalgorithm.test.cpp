#include <bits/stdc++.h>
#include "文字列/文字列アルゴリズム.hpp"
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
int main() { string s; cin >> s; auto z = z_algorithm(s); for (int i = 0; i < (int)z.size(); ++i) cout << z[i] << " \n"[i + 1 == (int)z.size()]; }
