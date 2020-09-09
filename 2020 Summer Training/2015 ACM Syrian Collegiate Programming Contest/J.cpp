#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
 
int n, m, num;
int vis[MAX];
string tb[MAX];
vector<int> ss[MAX];
map<string, int> mp;
 
void init() {
	num = 1;
	mp.clear();
	for (int i = 1; i < MAX; i++) {
		ss[i].clear();
		tb[i] = "";
	}
	memset(vis, 0, sizeof(vis));
}
 
void dfs(int p) {
	if (vis[p]) return;
	if (ss[p].size() == 0) {
		vis[p] = 1;
		return;
	}
	vis[p] = 1;
	for (auto i : ss[p]) if (!vis[i]) dfs(i);
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	int t; cin >> t;
	while (t--) {
		init();
 
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
 
			if (mp.find(s) == mp.end()) {
				mp[s] = num;
				tb[num] = s;
				num ++;
			}
			int p = mp[s];
 
			int r; cin >> r;
			while (r--) {
				cin >> s; 
				if (mp.find(s) == mp.end()) {
					mp[s] = num;
					tb[num] = s;
					num ++;
				}
				ss[p].push_back(mp[s]);
			}
			// cout << p << ' ' << r << '\n';
		}
		while (m--) {
			string s; cin >> s;
			dfs(mp[s]);
		}
		for (int i = 1; i < num; i++) if (vis[i]) {
			cout << tb[i] << '\n';
		}
		// cout << "Finish\n\n";
	}
	return 0;
}
