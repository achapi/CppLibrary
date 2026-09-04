#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#include "data_structure/双対セグ木.cpp"
#include "data_structure/mo.cpp"
#include "data_structure/重み付きUnionFind.cpp"
#include "geometry/幾何.cpp"
#include "graph/橋と関節点.cpp"
#include "graph/トポロジカルソート.cpp"
#include "math/組合せ.cpp"
#include "math/行列.cpp"
#include "math/整数論.cpp"
#include "string/ローリングハッシュ.cpp"
#include "string/文字列アルゴリズム.cpp"
#include "tree/重軽分解.cpp"
#include "tree/木の直径.cpp"

long long compose(long long f, long long g){
	return f + g;
}
long long identity(){
	return 0;
}

int main(){
	weighted_union_find<long long> uf(4);
	assert(uf.merge(0, 1, 3) and uf.merge(1, 2, -5));
	assert(uf.diff(0, 2).value() == -2 and !uf.merge(0, 2, 0));

	dual_segtree<long long, compose, identity> dual(5);
	dual.apply(1, 4, 7);
	dual.apply(2, 5, 3);
	assert(dual.get(0) == 0 and dual.get(1) == 7 and dual.get(2) == 10 and dual.get(4) == 3);

	lowlink ll(4);
	ll.add_edge(0, 1, 0);
	ll.add_edge(1, 2, 1);
	ll.add_edge(1, 3, 2);
	ll.build();
	assert(ll.bridges.size() == 3 and ll.articulation == std::vector<int>{1});

	std::vector<std::vector<int>> dag{{1, 2}, {3}, {3}, {}};
	assert(topological_sort(dag) == std::vector<int>({0, 1, 2, 3}));
	std::vector<std::vector<int>> unweighted_tree{{1, 2}, {0, 3}, {0}, {1}};
	heavy_light_decomposition hld(unweighted_tree);
	assert(hld.lca(1, 3) == 1 and hld.subtree(1).second - hld.subtree(1).first == 2);

	std::vector<std::vector<std::pair<int, int>>> tree(3);
	tree[0].push_back({1, 2});
	tree[1].push_back({0, 2});
	tree[1].push_back({2, 4});
	tree[2].push_back({1, 4});
	auto [diameter, s, t, path] = tree_diameter(tree);
	assert(diameter == 6 and path.size() == 3);

	rolling_hash rh("abracadabra", 911382323);
	assert(rh.get(0, 4) == rh.get(7, 11));
	assert(enumerate_palindromes("abacaba") ==
		   std::vector<int>({1, 0, 3, 0, 1, 0, 7, 0, 1, 0, 3, 0, 1}));

	using mint = atcoder::modint998244353;
	combinatorics<mint> comb(10);
	assert(comb.binom(10, 3).val() == 120);
	matrix<mint> a(2, 2);
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	assert(a.pow(5)[0][1].val() == 5 and a.determinant().val() == 998244352);
	assert(number_theory::floor_sum(4, 10, 6, 3) == 3);

	using P = point<long long>;
	auto hull = convex_hull(std::vector<P>{{0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}});
	assert(hull.size() == 4 and segments_intersect(P{0, 0}, P{2, 2}, P{0, 2}, P{2, 0}));
}
