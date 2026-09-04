#include <bits/stdc++.h>
using namespace std;
#include "math/整数論.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	while (q--){
		uint64_t n;
		cin >> n;
		auto f = number_theory::factorize(n);
		cout << f.size();
		for (auto p : f){
			cout << ' ' << p;
		}
		cout << endl;
	}
}
