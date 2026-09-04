vector<mint> stirling1(int n){
	auto f = [&](auto f, int l, int r) -> vector<mint> {
		if (r - l == 1){
			return {l, 1};
		}
		return atcoder::convolution(f(f, l, (l + r) / 2), f(f, (l + r) / 2, r));
	};
	return n ? f(f, 0, n) : vector<mint>{1};
}
