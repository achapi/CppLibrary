void cmbinit(){
	for(int i=2;i<5050505;i++){
		int mod = modint::mod();
		fact[i] = fact[-1] * i;
		inv[i] = -inv[mod % i] * (mod / i);
		factinv[i] = factinv[-1] * inv[-1];
	}
}
mint cmb(int n, int r){
	if(r<0 or n<r)return 0;
	return fact[n]*factinv[min(r,n-r)]*factinv[n-min(r,n-r)];
}
