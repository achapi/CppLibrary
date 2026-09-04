struct Rectangle{
	long long l, d, r, u;
};
struct RectangleUnion{
	struct S{
		int mn;
		long long len;
	};
	using F = int;
	struct Event{
		long long x, d, u;
		int v;
	};
	static S op(S l, S r){
		if (l.mn < r.mn) return l;
		if (l.mn > r.mn) return r;
		return {l.mn, l.len + r.len};
	}
	static S e(){
		return {(int)1e9, 0};
	}
	static S mapping(F f, S x){
		x.mn += f;
		return x;
	}
	static F composition(F f, F g){
		return f + g;
	}
	static F id(){
		return 0;
	}
	static long long area(vector<Rectangle> a){
		if (a.empty()) return 0;
		vector<Event> ev;
		vector<long long> y;
		for (int i = 0; i < (int)a.size(); i++){
			ev.push_back({a[i].l, a[i].d, a[i].u, 1});
			ev.push_back({a[i].r, a[i].d, a[i].u, -1});
			y.push_back(a[i].d);
			y.push_back(a[i].u);
		}
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		sort(ev.begin(), ev.end(), [](Event a, Event b){
			return a.x < b.x;
		});
		vector<S> v(y.size() - 1);
		long long all = 0;
		for (int i = 0; i + 1 < (int)y.size(); i++){
			v[i] = {0, y[i + 1] - y[i]};
			all += y[i + 1] - y[i];
		}
		atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
		long long ans = 0;
		int i = 0;
		while (i < (int)ev.size()){
			long long x = ev[i].x;
			int j = i;
			while (j < (int)ev.size() && ev[j].x == x){
				int d = lower_bound(y.begin(), y.end(), ev[j].d) - y.begin();
				int u = lower_bound(y.begin(), y.end(), ev[j].u) - y.begin();
				seg.apply(d, u, ev[j].v);
				j++;
			}
			if (j < (int)ev.size()){
				S s = seg.all_prod();
				long long len = s.mn == 0 ? all - s.len : all;
				ans += len * (ev[j].x - x);
			}
			i = j;
		}
		return ans;
	}
};
