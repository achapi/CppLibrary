template <class T> struct point {
	T x{}, y{};
	point operator+(point p) const {
		return {x + p.x, y + p.y};
	}
	point operator-(point p) const {
		return {x - p.x, y - p.y};
	}
	point operator*(T k) const {
		return {x * k, y * k};
	}
	auto operator<=>(const point&) const = default;
};
template <class T> T dot(point<T> a, point<T> b){
	return a.x * b.x + a.y * b.y;
}
template <class T> T cross(point<T> a, point<T> b){
	return a.x * b.y - a.y * b.x;
}
template <class T> T cross(point<T> a, point<T> b, point<T> c){
	return cross(b - a, c - a);
}
template <class T> int ccw(point<T> a, point<T> b, point<T> c){
	T z = cross(a, b, c);
	return (z > 0) - (z < 0);
}
template <class T>
vector<point<T>> convex_hull(vector<point<T>> p, bool include_collinear = false){
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	if (p.size() <= 1){
		return p;
	}
	vector<point<T>> h;
	auto bad = [&](point<T> a, point<T> b, point<T> c){
		T z = cross(a, b, c);
		return include_collinear ? z < 0 : z <= 0;
	};
	for (auto q : p){
		while (h.size() >= 2 and bad(h[h.size() - 2], h.back(), q)){
			h.pop_back();
		}
		h.push_back(q);
	}
	int lower = h.size();
	for (int i = (int)p.size() - 2; i >= 0; --i){
		auto q = p[i];
		while ((int)h.size() > lower and bad(h[h.size() - 2], h.back(), q)){
			h.pop_back();
		}
		h.push_back(q);
	}
	h.pop_back();
	return h;
}
template <class T> bool segments_intersect(point<T> a, point<T> b, point<T> c, point<T> d){
	auto sgn = [](T x){ return (x > 0) - (x < 0); };
	T ab_c = cross(a, b, c), ab_d = cross(a, b, d), cd_a = cross(c, d, a), cd_b = cross(c, d, b);
	if (!ab_c and !ab_d){
		return max(min(a, b), min(c, d)) <= min(max(a, b), max(c, d));
	}
	return sgn(ab_c) * sgn(ab_d) <= 0 and sgn(cd_a) * sgn(cd_b) <= 0;
}
