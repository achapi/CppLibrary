struct BinaryTrie{
	struct Node{
		int ch[2] = {-1, -1};
		int cnt = 0;
	};
	vector<Node> tr;
	BinaryTrie(){
		tr.push_back(Node());
	}
	void add(int x, int v){
		int p = 0;
		tr[p].cnt += v;
		for (int i = 29; i >= 0; i--){
			int b = x >> i & 1;
			if (tr[p].ch[b] == -1){
				tr[p].ch[b] = tr.size();
				tr.push_back(Node());
			}
			p = tr[p].ch[b];
			tr[p].cnt += v;
		}
	}
	int count(int x){
		int p = 0;
		for (int i = 29; i >= 0; i--){
			int b = x >> i & 1;
			if (tr[p].ch[b] == -1) return 0;
			p = tr[p].ch[b];
		}
		return tr[p].cnt;
	}
	int xor_min(int x){
		int p = 0, ans = 0;
		for (int i = 29; i >= 0; i--){
			int b = x >> i & 1;
			int q = tr[p].ch[b];
			if (q != -1 && tr[q].cnt > 0){
				p = q;
			} else {
				p = tr[p].ch[b ^ 1];
				ans |= 1 << i;
			}
		}
		return ans;
	}
};
