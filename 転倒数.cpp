#include <atcoder/fenwicktree>
template<typename T>
vector<int> inversion_count(const vector<T>& a) {
	int n = a.size();
	vector<T> sorted = a;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	vector<int> comp(n);
	for (int i = 0; i < n; i++) {
		comp[i] = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
	}
	atcoder::fenwick_tree<int> fw(sorted.size());
	vector<int> inv(n);
	for (int i = 0; i < n; i++) {
		inv[i] = i - fw.sum(0, comp[i] + 1);
		fw.add(comp[i], 1);
	}
	return inv;
}
