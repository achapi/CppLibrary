vector<mint> manhattan_distance_distribution(int n, int m) {
	vector<mint> res(n + m - 1);
	res[0] = mint(n) * m;
	for (int d = 1; d < n + m - 1; d++) {
		int l = max(1, d - m + 1), r = min(n - 1, d - 1);
		res[d] = mint(n) * max(0, m - d) + mint(m) * max(0, n - d);
		if (l <= r) res[d] += 2 * (mint(n) * (m - d) * (r - l + 1) + mint(n - m + d) * (l + r) * (r - l + 1) / 2 - (mint(r) * (r + 1) * (2 * r + 1) - mint(l - 1) * l * (2 * l - 1)) / 6);
	}
	return res;
}
