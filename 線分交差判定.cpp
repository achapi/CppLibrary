bool is_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int s = (x1 - x2) * (y3 - y1) - (y1 - y2) * (x3 - x1);
	int t = (x1 - x2) * (y4 - y1) - (y1 - y2) * (x4 - x1);
	if ((long long) s * t > 0){
		return false;
	}
	s = (x3 - x4) * (y1 - y3) - (y3 - y4) * (x1 - x3);
	t = (x3 - x4) * (y2 - y3) - (y3 - y4) * (x2 - x3);
	if ((long long) s * t > 0){
		return false;
	}
	if ((long long) s * t == 0){
		if (abs(sqrt((x1 - x3) * (x1 - x3)) + sqrt((x2 - x3) * (x2 - x3)) - sqrt((x1 - x2) * (x1 - x2))) <= 1e-9){
			return true;
		}
		if (abs(sqrt((x1 - x4) * (x1 - x4)) + sqrt((x2 - x4) * (x2 - x4)) - sqrt((x1 - x2) * (x1 - x2))) <= 1e-9){
			return true;
		}
		if (abs(sqrt((x3 - x1) * (x3 - x1)) + sqrt((x4 - x1) * (x4 - x1)) - sqrt((x3 - x4) * (x3 - x4))) <= 1e-9){
			return true;
		}
		if (abs(sqrt((x3 - x2) * (x3 - x2)) + sqrt((x4 - x2) * (x4 - x2)) - sqrt((x3 - x4) * (x3 - x4))) <= 1e-9){
			return true;
		}
		return false;
	}
	return true;
}
