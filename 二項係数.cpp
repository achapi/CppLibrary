for (int i = 1; i < 1010101; i++){
	fact.push_back(fact.back() * mint(i));
	rev.push_back(fact.back().inv());
}
auto cmb = [&](int n, int r) -> mint {
	if (n < r){
		return mint(0);
	}
	return fact[n] * rev[n - r] * rev[r];
};
