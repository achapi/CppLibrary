struct RollingHash {
	static const int BASE = 334;
	static const int MOD = 1145140019;
	vector<long long> hash, power;

	RollingHash(const string &s) {
		int n = (int)s.size();
		hash.assign(n + 1, 0);
		power.assign(n + 1, 1);
		for (int i = 0; i < n; i++) {
			hash[i + 1] = (hash[i] * BASE + s[i]) % MOD;
			power[i + 1] = (power[i] * BASE) % MOD;
		}
	}

	inline long long get(int l, int r) const {
		long long res = hash[r] - hash[l] * power[r-l] % MOD;
		if (res < 0){
			res += MOD;
		}
		return res;
	}
};
