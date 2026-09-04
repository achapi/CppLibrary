#include <bits/stdc++.h>
using namespace std;
#include "data_structure/スパーステーブル.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
int op(int a, int b){
	return min(a, b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& x : a){
		cin >> x;
	}
	sparse_table<int, op> st(a);
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << st.prod(l, r) << endl;
	}
}
