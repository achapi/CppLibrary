struct RollingHash {
	static const int BASE1 = 334000013;
	static const int MOD1 = 1145140019;
	static const int BASE2 = 364364003;
	static const int MOD2 = 1919810021;
	vector<long long> hash1, power1, hash2, power2;
	RollingHash(const string &s) {
		int n = (int) s.size();
		hash1.assign(n + 1, 0);
		power1.assign(n + 1, 1);
		for (int i = 0; i < n; i++) {
			hash1[i + 1] = (hash1[i] * BASE1 + s[i]) % MOD1;
			power1[i + 1] = (power1[i] * BASE1) % MOD1;
		}
		hash2.assign(n + 1, 0);
		power2.assign(n + 1, 1);
		for (int i = 0; i < n; i++) {
			hash2[i + 1] = (hash2[i] * BASE2 + s[i]) % MOD2;
			power2[i + 1] = (power2[i] * BASE2) % MOD2;
		}
	}
	inline long long get(int l, int r) const {
		long long res1 = hash1[r] - hash1[l] * power1[r-l] % MOD1;
		if (res1 < 0){
			res1 += MOD1;
		}
		long long res2 = hash2[r] - hash2[l] * power2[r-l] % MOD2;
		if (res2 < 0){
			res2 += MOD2;
		}
		return res1 * res2;
	}
};
