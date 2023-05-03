template<class T>struct cumulative_sum_2d {
	/* 1-indexed */
	int h, w;
	vector<vector<T>> vec;
	vector<vector<T>> vec2;
	cumulative_sum_2d(vector<vector<T>> a){
		h = a.size();
		w = a.front().size();
		vec.resize(h + 1, vector<T>(w + 1));
		vec2 = a;
	}
	void build(){
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				vec[i + 1][j + 1] = vec[i][j + 1] + vec[i + 1][j] - vec[i][j] + vec2[i][j];
			}
		}
	}
	void add(pair<int, int> p1, pair<int, int> p2, T c){
		if (p1 > p2){
			swap(p1, p2);
		}
		vec2[p1.first - 1][p1.second - 1] += c;
		vec2[p1.first - 1][p2.second] -= c;
		vec2[p2.first][p1.second - 1] -= c;
		vec2[p2.first][p2.second] += c;
	}
	T query(pair<int, int> p1, pair<int, int> p2){
		if (p1 > p2){
			swap(p1, p2);
		}
		return vec[p2.first][p2.second] - vec[p1.first - 1][p2.second] - vec[p2.first][p1.second - 1] + vec[p1.first - 1][p1.second - 1];
	}
};
