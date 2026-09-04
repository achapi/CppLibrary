struct ImplicitTreap {
	struct Node {
		mint val, sum;
		mint a = 1, b = 0;
		int l = -1, r = -1, sz = 1;
		mt19937::result_type pri;
		bool rev = false;
	};
	vector<Node> tr;
	int root = -1;
	mt19937 rng{
		static_cast<mt19937::result_type>(chrono::steady_clock::now().time_since_epoch().count())};
	int make(mint x){
		tr.push_back({x, x, 1, 0, -1, -1, 1, rng(), false});
		return tr.size() - 1;
	}
	int size(int p){
		return p == -1 ? 0 : tr[p].sz;
	}
	mint sum(int p){
		return p == -1 ? 0 : tr[p].sum;
	}
	void pull(int p){
		tr[p].sz = size(tr[p].l) + 1 + size(tr[p].r);
		tr[p].sum = sum(tr[p].l) + tr[p].val + sum(tr[p].r);
	}
	void apply_affine(int p, mint a, mint b){
		if (p == -1){
			return;
		}
		tr[p].val = a * tr[p].val + b;
		tr[p].sum = a * tr[p].sum + b * tr[p].sz;
		tr[p].a = a * tr[p].a;
		tr[p].b = a * tr[p].b + b;
	}
	void apply_rev(int p){
		if (p == -1){
			return;
		}
		swap(tr[p].l, tr[p].r);
		tr[p].rev ^= 1;
	}
	void push(int p){
		if (p == -1){
			return;
		}
		if (tr[p].rev){
			apply_rev(tr[p].l);
			apply_rev(tr[p].r);
			tr[p].rev = false;
		}
		if (tr[p].a != 1 or tr[p].b != 0){
			apply_affine(tr[p].l, tr[p].a, tr[p].b);
			apply_affine(tr[p].r, tr[p].a, tr[p].b);
			tr[p].a = 1;
			tr[p].b = 0;
		}
	}
	pair<int, int> split(int p, int k){
		if (p == -1){
			return {-1, -1};
		}
		push(p);
		if (size(tr[p].l) >= k){
			pair<int, int> q = split(tr[p].l, k);
			tr[p].l = q.second;
			pull(p);
			return {q.first, p};
		}
		pair<int, int> q = split(tr[p].r, k - size(tr[p].l) - 1);
		tr[p].r = q.first;
		pull(p);
		return {p, q.second};
	}
	int merge(int a, int b){
		if (a == -1){
			return b;
		}
		if (b == -1){
			return a;
		}
		if (tr[a].pri > tr[b].pri){
			push(a);
			tr[a].r = merge(tr[a].r, b);
			pull(a);
			return a;
		}
		push(b);
		tr[b].l = merge(a, tr[b].l);
		pull(b);
		return b;
	}
	ImplicitTreap(vector<mint> a = {}){
		for (int i = 0; i < (int)a.size(); i++){
			root = merge(root, make(a[i]));
		}
	}
	void insert(int p, mint x){
		pair<int, int> q = split(root, p);
		root = merge(q.first, merge(make(x), q.second));
	}
	void erase(int p){
		pair<int, int> q = split(root, p);
		pair<int, int> r = split(q.second, 1);
		root = merge(q.first, r.second);
	}
	void reverse(int l, int r){
		pair<int, int> p = split(root, l);
		pair<int, int> q = split(p.second, r - l);
		apply_rev(q.first);
		root = merge(p.first, merge(q.first, q.second));
	}
	void apply(int l, int r, mint a, mint b){
		pair<int, int> p = split(root, l);
		pair<int, int> q = split(p.second, r - l);
		apply_affine(q.first, a, b);
		root = merge(p.first, merge(q.first, q.second));
	}
	mint prod(int l, int r){
		pair<int, int> p = split(root, l);
		pair<int, int> q = split(p.second, r - l);
		mint ans = sum(q.first);
		root = merge(p.first, merge(q.first, q.second));
		return ans;
	}
};
