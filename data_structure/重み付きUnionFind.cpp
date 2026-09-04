template <class T> struct weighted_union_find {
	vector<int> p, sz;
	vector<T> w; // potential(x) - potential(parent(x))
	explicit weighted_union_find(int n) : p(n), sz(n, 1), w(n, T{}){
		iota(p.begin(), p.end(), 0);
	}
	int leader(int x){
		if (p[x] == x){
			return x;
		}
		int q = p[x];
		p[x] = leader(q);
		w[x] += w[q];
		return p[x];
	}
	T potential(int x){
		leader(x);
		return w[x];
	}
	bool same(int x, int y){
		return leader(x) == leader(y);
	}
	// Enforces potential(y) - potential(x) = d. Returns false on contradiction.
	bool merge(int x, int y, T d){
		d += potential(x) - potential(y);
		x = leader(x), y = leader(y);
		if (x == y){
			return d == T{};
		}
		if (sz[x] < sz[y]){
			swap(x, y);
			d = -d;
		}
		p[y] = x;
		sz[x] += sz[y];
		w[y] = d;
		return true;
	}
	optional<T> diff(int x, int y){
		if (!same(x, y)){
			return nullopt;
		}
		return potential(y) - potential(x);
	}
};
