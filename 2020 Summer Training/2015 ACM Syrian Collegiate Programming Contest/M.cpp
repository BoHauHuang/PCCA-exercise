#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
 
struct wok {
	int sta, end;
 
	bool operator < (const wok& rhs) const {
		if (sta != rhs.sta) return sta < rhs.sta;
		return end < rhs.end;
	}
};
 
int n, num;
vector<wok> v[MAX];
vector<string> ans;
map<int, string> tab;
map<string, int> mp;
 
void init() {
	num = 1;
	mp.clear();
	ans.clear();
	tab.clear();
	for (int i = 0; i < MAX; i++) v[i].clear();
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	string s;
 
	int t; cin >> t;
	while (t--) {
		init();
 
		cin >> n;
		for (int i = 1; i <= n; i++) {
			wok w; cin >> s >> w.sta >> w.end;
			int m; cin >> m;
			while (m--) {
				cin >> s;
				if (mp.find(s) == mp.end()) {
					mp[s] = num;
					tab[num] = s;
					num++;
					// cout << s << ' ' << num - 1 << endl;
				}
				v[mp[s]].push_back(w);
			}
		}
 
		for (int i = 1; i < num; i++) {
			sort(v[i].begin(), v[i].end());
 
			int edt = 0;
			for (auto j : v[i]) {
				if (j.sta <= edt) {
					ans.push_back(tab[i]);
					break;
				}
				edt = j.end;
			}
		}
		sort(ans.begin(), ans.end());
 
		cout << ans.size() << '\n';
		for (auto i : ans) cout << i << '\n';
	}
	return 0;
}
