bool is_prime(long long N) {
	if (N == 2) return true;
	if (N == 1 or N % 2 == 0) return false;
	vector<int> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	int s = 0;
	long long d = N - 1;
	while (d % 2 == 0) {
		s++;
		d >>= 1;
	}
	for (auto a : A) {
		if (a % N == 0) return true;
		auto pow_mod = [](__int128_t A, long long N, long long M) -> long long {
			__int128_t res = 1 % M;
			A %= M;
			while (N) {
				if (N & 1) res = (res * A) % M;
				A = (A * A) % M;
				N >>= 1;
			}
			return res;
		};
		long long t, x = pow_mod(a, d, N);
		if (x != 1) {
			for (t = 0; t < s; t++) {
				if (x == N - 1) break;
				x = __int128_t(x) * x % N;
			}
			if (t == s) return false;
		}
	}
	return true;
}
