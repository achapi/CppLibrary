vector<int> eratosthenes(){
	int MAX = 2000000;
	vector<int> e(MAX + 1);
	for (int i = 2; i <= MAX; i++){
		for (int j = i; j <= MAX; j += i){
			e[j]++;
		}
	}
	vector<int> p;
	for (int i = 2; i <= MAX; i++){
		if (e[i] == 1){
			p.push_back(i);
		}
	}
	return p;
}
