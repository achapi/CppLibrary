template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
	vector<T> vals;
	int n = (int)C1.size();
	for (int i = 0; i < n; i++) {
		for (T d = 0; d <= 1; d++) {
			T tc1 = C1[i] + d;
			T tc2 = C2[i] + d;
			vals.push_back(tc1);
			vals.push_back(tc2);
		}
	}
 
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; i++) {
		C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
		C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
	}
	return vals;
}
