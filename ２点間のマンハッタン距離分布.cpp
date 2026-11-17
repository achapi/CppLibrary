vector<mint> manhattan_distance_distribution(int n, int m) {
	vector<mint> cnt(n + m - 1);
	cnt[0] = mint(n) * m;
	auto sum1 = [](long long x) -> mint {
		return mint(x) * (x + 1) / 2;
	};
	auto sum2 = [](long long x) -> mint {
		return mint(x) * (x + 1) * (2 * x + 1) / 6;
	};
	for (int d = 1; d < n + m - 1; d++) {
		if (d < m) cnt[d] += mint(n) * (m - d);
		if (d < n) cnt[d] += mint(m) * (n - d);
		int l = max(1, d - m + 1);
		int r = min(n - 1, d - 1);
		if (l > r) continue;
		mint s0 = r - l + 1;
		mint s1 = sum1(r) - sum1(l - 1);
		mint s2 = sum2(r) - sum2(l - 1);
		cnt[d] += 2 * (mint(n) * (m - d) * s0 + mint(n - m + d) * s1 - s2);
	}
	return cnt;
}
