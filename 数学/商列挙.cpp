vector<long long> enumerate_quotients(long long n){
	long long q = sqrtl(n);
	set<long long> s;
	for (long long i = 1; i <= q; i++){
		s.insert(n / i);
		s.insert(n / (n / i));
	}
	return vector<long long>(s.begin(), s.end());
}
