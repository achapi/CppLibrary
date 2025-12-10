struct SuffixAutomaton {
	struct State {
		int link;
		int len;
		map<char, int> next;
		State() : link(-1), len(0) {}
	};
	vector<State> st;
	int last;
	SuffixAutomaton() {
		st.emplace_back();
		last = 0;
	}
	void extend(char c) {
		int cur = st.size();
		st.emplace_back();
		st[cur].len = st[last].len + 1;
		int p = last;
		while (p != -1 && !st[p].next.count(c)) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int clone = st.size();
				st.push_back(st[q]);
				st[clone].len = st[p].len + 1;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = clone;
					p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
	bool match(const string &p) {
		int v = 0;
		for (char c : p) {
			if (!st[v].next.count(c)) return false;
			v = st[v].next[c];
		}
		return true;
	}
};
