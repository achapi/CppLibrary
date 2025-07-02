#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
#include <atcoder/all>
using mint = atcoder::modint998244353;
#include <atcoder/all>
using mint = atcoder::modint1000000007;
#include <atcoder/all>
using mint = atcoder::modint;
#define all(...) begin(__VA_ARGS__), end(__VA_ARGS__)
//debug
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
using Graph = vector<vector<int>>;
struct Edge {
	int to;
	long long cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<long long, int>;
const int inf = INT_MAX / 2;
const long long infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; };
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; };
bool ok;
int main() {
	if (ok){
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
}
// python3 expander.py AC.cpp
// g++ AC.cpp -Wall -Wextra -O2 -std=c++20 -I . -DLOCAL