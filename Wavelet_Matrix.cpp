struct Wavelet_Matrix{
	int H, N;
	vector<vector<int>> dat;
	Wavelet_Matrix(int H, vector<int> A){
		this->H = H;
		N = A.size();
		dat.resize(H);
		for (int h = H - 1; h >= 0; h--){
			vector<int> dir(N), left, right;
			for (int i = 0; i < N; i++){
				dir[i] = A[i] >> h & 1;
				if (dir[i] == 0){
					left.push_back(A[i]);
				} else {
					right.push_back(A[i]);
				}
			}
			for (int i = 0; i < (int) left.size(); i++){
				A[i] = left[i];
			}
			for (int i = 0; i < (int) right.size(); i++){
				A[left.size() + i] = right[i];
			}
			dat[h].resize(N + 1);
			for (int i = 0; i < N; i++){
				dat[h][i + 1] = dat[h][i] + dir[i];
			}
		}
	}
	int kth_smallest(int L, int R, int k){
		assert(0 <= L and L < R and R <= N and 0 <= k and k < R - L);
		return kth_smallest_rec(H, L, R, k);
	}
	int kth_smallest_rec(int h, int l, int r, int k){
		if (h == 0){
			return 0;
		}
		int l0 = l - dat[h - 1][l], r0 = r - dat[h - 1][r], l1 = N - dat[h - 1][N] + dat[h - 1][l], r1 = N - dat[h - 1][N] + dat[h - 1][r], left_size = r0 - l0;
		if (k < left_size){
			return kth_smallest_rec(h - 1, l0, r0, k);
		} else {
			return (1 << (h - 1)) + kth_smallest_rec(h - 1, l1, r1, k - left_size);
		}
	}
};
