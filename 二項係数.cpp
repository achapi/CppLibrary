vector<mint> fact = {1};
for (int i = 1; i < 10101010; i++){
	fact.push_back(fact.back() * mint(i));
}
auto cmb = [&](int n, int r) -> mint {
	if (n < r){
		return mint(0);
	}
	return fact[n] / fact[n - r] / fact[r];
};
