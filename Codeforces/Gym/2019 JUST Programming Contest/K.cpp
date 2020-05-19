#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		unordered_set<int>st,cur;
		int n;
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			int add;
			cin >> add;
			unordered_set<int>nxt{add};
			for (auto j:cur) {
				nxt.insert(add|j);
			}
			st.insert(nxt.begin(),nxt.end());
			cur.swap(nxt);
		}
		cout << st.size() << '\n';
	}
	
	
	return 0;
}

