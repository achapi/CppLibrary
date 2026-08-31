long long count_primes(long long N){
	if (N < 2) return 0;
	int S = sqrtl(N);
	vector<long long> a(S + 1), b(S + 1);
	for (int i = 1; i <= S; i++){
		a[i] = i - 1;
		b[i] = N / i - 1;
	}
	for (long long p = 2; p <= S; p++){
		if (a[p] != a[p - 1]){
			long long c = a[p - 1];
			int R = min<long long>(S, N / (p * p));
			int M = min<long long>(R, S / p);
			for (int i = 1; i <= M; i++){
				b[i] -= b[i * p] - c;
			}
			for (int i = M + 1; i <= R; i++){
				b[i] -= a[N / (i * p)] - c;
			}
			for (long long i = S; i >= p * p; i--){
				a[i] -= a[i / p] - c;
			}
		}
	}
	return b[1];
}
