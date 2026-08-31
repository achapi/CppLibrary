struct S {
	long long a;
	int size;
};
struct F {
	long long a, b;
};
S op(S l, S r){
	return S{l.a + r.a, l.size + r.size};
}
S e(){
	return S{0, 0};
}
S mapping(F l, S r){
	return S{r.a * l.a + r.size * l.b, r.size};
}
F composition(F l, F r){
	return F{r.a * l.a, r.b * l.a + l.b};
}
F id(){
	return F{1, 0};
}
atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg();
