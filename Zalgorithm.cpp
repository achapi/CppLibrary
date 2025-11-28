vector<int> Zalgorithm(string S){
	vector<int> V(S.size());
	V[0] = S.size();
	int i = 1, j = 0;
	while (i < (int) S.size()){
		while (i + j < (int) S.size() and S[j] == S[i + j]){
			j++;
		}
		V[i] = j;
		if (j == 0){
			i++;
			continue;
		}
		int k = 1;
		while (i + k < (int) S.size() and k + V[k] < j){
			V[i + k] = V[k];
			k++;
		}
		i += k;
		j -= k;
	}
	return V;
}
