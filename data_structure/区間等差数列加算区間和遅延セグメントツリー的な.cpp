#include <bits/stdc++.h>
#include <atcoder/all>
using mint = atcoder::modint998244353;
using namespace std;
struct S{
	mint sum;
	mint idx_sum;
	int len;
};
struct F{
	mint a, b;
};
S op(S l, S r){
	return {
		l.sum + r.sum,
		l.idx_sum + r.idx_sum,
		l.len + r.len
	};
}
S e(){
	return {0, 0, 0};
}
S mapping(F f, S x){
	x.sum += f.a * x.idx_sum + f.b * x.len;
	return x;
}
F composition(F f, F g){
	return {f.a + g.a, f.b + g.b};
}
F id(){
	return {0, 0};
}
int main(){
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> C(N);
	vector<mint> B(N);
	mint sum = 0;
	for (int i = 0; i < N; i++){
		sum += A[i];
		B[i] = sum;
	}
	sum = 0;
	for (int i = 0; i < N; i++){
		sum += B[i];
		C.set(i, {sum, i, 1});
	}
	while (Q--){
		int t;
		cin >> t;
		if (t == 1){
			int x, v;
			cin >> x >> v;
			x--;
			C.apply(x, N, {v - A[x], -mint(x - 1) * (v - A[x])});
			A[x] = v;
		}
		if (t == 2){
			int x;
			cin >> x;
			cout << C.prod(0, x).sum.val() << endl;
		}
	}
}
