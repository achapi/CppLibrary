void fwht(vector<mint> &a){
	int n = a.size();
	for (int len = 1; len < n; len *= 2){
		for (int i = 0; i < n; i += len * 2){
			for (int j = 0; j < len; j++){
				mint x = a[i + j];
				mint y = a[i + j + len];
				a[i + j] = x + y;
				a[i + j + len] = x - y;
			}
		}
	}
}
vector<mint> xor_convolution(vector<mint> a, vector<mint> b){
	int n = a.size();
	fwht(a);
	fwht(b);
	for (int i = 0; i < n; i++) a[i] *= b[i];
	fwht(a);
	mint inv = mint(n).inv();
	for (int i = 0; i < n; i++) a[i] *= inv;
	return a;
}
