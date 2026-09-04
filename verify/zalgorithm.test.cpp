#include <bits/stdc++.h>
using namespace std;
#include "string/文字列アルゴリズム.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
int main(){
	string s;
	cin >> s;
	auto z = z_algorithm(s);
	for (int i = 0; i < (int)z.size(); ++i){
		cout << z[i];
		if (i + 1 == (int)z.size()){
			cout << endl;
		} else {
			cout << ' ';
		}
	}
}
