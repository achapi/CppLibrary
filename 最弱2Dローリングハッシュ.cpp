struct RollingHash2D {
	static const long long BASEX = 334000013;
	static const long long BASEY = 364364003;
	static const long long MOD  = 1145140019;
	vector<vector<long long>> hash;
	vector<long long> powX, powY;
	RollingHash2D(const vector<string> &s) {
		int H = s.size();
		int W = s[0].size();
		powX.assign(H + 1, 1);
		powY.assign(W + 1, 1);
		for (int x = 0; x < H; x++) powX[x + 1] = powX[x] * BASEX % MOD;
		for (int y = 0; y < W; y++) powY[y + 1] = powY[y] * BASEY % MOD;
		hash.assign(H + 1, vector<long long>(W + 1, 0));
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				long long v = s[x][y];
				long long a = hash[x][y + 1] * BASEX % MOD;
				long long b = hash[x + 1][y] * BASEY % MOD;
				long long c = hash[x][y] * BASEX % MOD * BASEY % MOD;
				long long cur = (v + a + b - c) % MOD;
				if (cur < 0) cur += MOD;
				hash[x + 1][y + 1] = cur;
			}
		}
	}
	inline long long get(int x1, int y1, int x2, int y2) const {
		int dx = x2 - x1;
		int dy = y2 - y1;
		long long res = hash[x2][y2];
		res -= hash[x1][y2] * powX[dx] % MOD;
		res -= hash[x2][y1] * powY[dy] % MOD;
		res += hash[x1][y1] * powX[dx] % MOD * powY[dy] % MOD;
		res %= MOD;
		if (res < 0) res += MOD;
		return res;
	}
};
