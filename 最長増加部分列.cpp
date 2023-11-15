template<class T> vector<T> LIS(vector<T> A) {
	vector<T> dp;
	int N = A.size();
	for (int i = 0; i < N; i++){
		if (dp.empty() or dp.back() < A[i]){
			dp.push_back(A[i]);
		} else {
			int k = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
			dp[k] = A[i];
		}
	}
	return dp;
}
