template <class T> struct matrix {
	int h, w;
	vector<vector<T>> a;
	matrix(int h = 0, int w = 0) : h(h), w(w), a(h, vector<T>(w)){}
	vector<T>& operator[](int i){
		return a[i];
	}
	const vector<T>& operator[](int i) const {
		return a[i];
	}
	static matrix identity(int n){
		matrix r(n, n);
		for (int i = 0; i < n; ++i){
			r[i][i] = 1;
		}
		return r;
	}
	friend matrix operator*(const matrix& x, const matrix& y){
		assert(x.w == y.h);
		matrix z(x.h, y.w);
		for (int i = 0; i < x.h; ++i){
			for (int k = 0; k < x.w; ++k){
				for (int j = 0; j < y.w; ++j){
					z[i][j] += x[i][k] * y[k][j];
				}
			}
		}
		return z;
	}
	matrix pow(long long n) const {
		assert(h == w);
		matrix x = *this, r = identity(h);
		while (n){
			if (n & 1){
				r = r * x;
			}
			x = x * x;
			n >>= 1;
		}
		return r;
	}
	T determinant() const {
		assert(h == w);
		matrix b = *this;
		T det = 1;
		for (int i = 0; i < h; ++i){
			int p = i;
			while (p < h and b[p][i] == T{}){
				++p;
			}
			if (p == h){
				return 0;
			}
			if (p != i){
				swap(b[p], b[i]), det = -det;
			}
			det *= b[i][i];
			T inv = T(1) / b[i][i];
			for (int j = i + 1; j < h; ++j){
				T q = b[j][i] * inv;
				for (int k = i; k < h; ++k){
					b[j][k] -= q * b[i][k];
				}
			}
		}
		return det;
	}
};
