template <bool Strict, class T>vector<int> LIS(const vector<T>& v) {
	vector<T> dp;
	auto it = dp.begin();
	vector<int> positions;
	for (const auto& elem : v) {
		if constexpr (Strict) it = lower_bound(dp.begin(), dp.end(), elem);
		else it = upper_bound(dp.begin(), dp.end(), elem);
		positions.push_back((int)(it - dp.begin()));
		if (it == dp.end()) dp.push_back(elem);
		else *it = elem;
	}
	vector<int> subseq(dp.size());
	int si = (int) subseq.size() - 1;
	int pi = (int) positions.size() - 1;
	while (0 <= si && 0 <= pi) {
		if (positions[pi] == si) {
			subseq[si] = pi;
			si--;
		}
		pi--;
	}
	return subseq;
}
