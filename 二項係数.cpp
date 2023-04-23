vector<mint> fact = {1};
for (int i = 1; i < 1010101; i++){
	fact.push_back(fact.back() * mint(i));
}
auto cmb = [&](int n,int r){
	return fact[n] / fact[n - r] / fact[r];
};
