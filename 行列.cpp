template<class T> struct Matrix{
	vector<vector<T>> A;
	Matrix(){}
	Matrix(int n, int m): A(n, vector<T>(m, 0)){}
	Matrix(int n): A(n, vector<T>(n, 0)){}
	int height() const{
		return A.size();
	}
	int width() const{
		return A[0].size();
	}
	const vector<T>& operator[](int k) const{
		return A[k];
	}
	vector<T>& operator[](int k){
		return A[k];
	}
	static Matrix I(int n){
		Matrix res(n);
		for (int i = 0; i < n; i++) res[i][i] = 1;
		return res;
	}
	Matrix& operator+=(const Matrix& B){
		int n = height(), m = width();
		assert(n == B.height() && m == B.width());
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				A[i][j] += B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator-=(const Matrix& B){
		int n = height(), m = width();
		assert(n == B.height() && m == B.width());
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				A[i][j] -= B[i][j];
			}
		}
		return *this;
	}
	Matrix& operator*=(const Matrix& B){
		int n = height(), m = B.width(), p = width();
		assert(p == B.height());
		vector<vector<T>> C(n, vector<T>(m, 0));
		for (int i = 0; i < n; i++){
			for (int k = 0; k < p; k++){
				for (int j = 0; j < m; j++){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		A.swap(C);
		return *this;
	}
	Matrix& operator^=(long long k){
		Matrix res = I(height());
		Matrix x = *this;
		while(k){
			if (k & 1) res *= x;
			x *= x;
			k >>= 1;
		}
		A.swap(res.A);
		return *this;
	}
	Matrix operator+(const Matrix& B) const{
		Matrix res = *this;
		return res += B;
	}
	Matrix operator-(const Matrix& B) const{
		Matrix res = *this;
		return res -= B;
	}
	Matrix operator*(const Matrix& B) const{
		Matrix res = *this;
		return res *= B;
	}
	Matrix operator^(long long k) const{
		Matrix res = *this;
		return res ^= k;
	}
	friend ostream& operator<<(ostream& os, const Matrix& M){
		for (int i = 0; i < M.height(); i++){
			os << "[";
			for (int j = 0; j < M.width(); j++){
				os << M[i][j] << (j + 1 == M.width() ? "]\n" : ",");
			}
		}
		return os;
	}
	T determinant() const{
		Matrix B = *this;
		assert(height() == width());
		T res = 1;
		for (int i = 0; i < width(); i++){
			int p = -1;
			for (int j = i; j < width(); j++){
				if (B[j][i] != 0){
					p = j;
					break;
				}
			}
			if (p == -1) return 0;
			if (i != p){
				swap(B[i], B[p]);
				res *= -1;
			}
			res *= B[i][i];
			T v = B[i][i];
			for (int j = 0; j < width(); j++){
				B[i][j] /= v;
			}
			for (int j = i + 1; j < width(); j++){
				T c = B[j][i];
				for (int k = 0; k < width(); k++){
					B[j][k] -= B[i][k] * c;
				}
			}
		}
		return res;
	}
};
