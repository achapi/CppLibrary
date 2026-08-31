vector<pair<char, int>> RLE(string S){
	int N = S.size();
	vector<pair<char, int>> ret;
	for (int l = 0; l < N;){
		int r = l + 1;
		while (r < N and S[l] == S[r]){
			r++;
		};
		ret.push_back(make_pair(S[l], r - l));
		l = r;
	}
	return ret;
}

template<class T>vector<pair<int, int>> RLE(vector<T> A){
	int N = A.size();
	vector<pair<int, int>> ret;
	for (int l = 0; l < N;){
		int r = l + 1;
		while (r < N and A[l] == A[r]){
			r++;
		};
		ret.push_back({A[l], r - l});
		l = r;
	}
	return ret;
}
