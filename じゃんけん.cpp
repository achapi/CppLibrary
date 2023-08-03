auto RPS = [](char a, char b) -> char {
	if (a == b){
		return a;
	} else {
		if ((a == 'R' and b == 'S') or (a == 'S' and b == 'R')){
			return 'R';
		}
		if ((a == 'S' and b == 'P') or (a == 'P' and b == 'S')){
			return 'S';
		}
		if ((a == 'P' and b == 'R') or (a == 'R' and b == 'P')){
			return 'P';
		}
	}
};
