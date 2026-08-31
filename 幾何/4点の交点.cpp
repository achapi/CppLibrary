struct xy{
	double x;
	double y;
};
pair<double, double> cross(xy p1, xy p2, xy p3, xy p4){
	double s1 = (p4.x - p2.x) * (p1.y - p2.y) - (p4.y - p2.y) * (p1.x - p2.x);
	double s2 = (p4.x - p2.x) * (p2.y - p3.y) - (p4.y - p2.y) * (p2.x - p3.x);
	s1 /= 2;
	s2 /= 2;
	if (s1 + s2 == 0){
		return make_pair(1e18, 1e18);
	}
	return make_pair(p1.x + (p3.x - p1.x) * s1 / (s1 + s2), p1.y + (p3.y - p1.y) * s1 / (s1 + s2));
}
