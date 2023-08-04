bool is_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	double s = (x1 - x2) * (y3 - y1) - (y1 - y2) * (x3 - x1);
	double t = (x1 - x2) * (y4 - y1) - (y1 - y2) * (x4 - x1);
	if (s * t > 0){
		return false;
	}
	s = (x3 - x4) * (y1 - y3) - (y3 - y4) * (x1 - x3);
	t = (x3 - x4) * (y2 - y3) - (y3 - y4) * (x2 - x3);
	if (s * t > 0){
		return false;
	}
	return true;
}
