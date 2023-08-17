vector<string> RPN(string S) {
	vector<string> A;
	vector<stack<int>> st(1);
	/* Only four arithmetic operations */
	string support = '0123456789+-*/()';
	for (int i = 0; i < (int) S.size(); i++){
		if (support.find(S[i]) == string::npos){
			continue;
		}
		if (S[i] == '('){
			st.resize(st.size() + 1);
		} else if (S[i] == ')'){
			while (!st.back().empty()){
				A.resize(A.size() + 1);
				A.back().push_back(st.back().top());
				st.back().pop();
			}
			st.pop_back();
		} else {
			if (isdigit(S[i])){
				if (i == 0 or !isdigit(S[i - 1])){
					A.resize(A.size() + 1);
				}
				A.back().push_back(S[i]);
			} else {
				debug(st);
				if ((int) st.back().size() >= 2 and (S[i] == '+' or S[i] == '-')){
					while (!st.back().empty()){
						A.resize(A.size() + 1);
						A.back().push_back(st.back().top());
						st.back().pop();
					}
				}
				st.back().push(S[i]);
			}
		}
	}
	while (!st.back().empty()){
		A.resize(A.size() + 1);
		A.back().push_back(st.back().top());
		st.back().pop();
	}
	return A;
}
