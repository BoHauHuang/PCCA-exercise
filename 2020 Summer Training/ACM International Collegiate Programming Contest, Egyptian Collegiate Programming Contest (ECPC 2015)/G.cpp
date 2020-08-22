#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 0x3f3f3f3f
#define MAX 100010
 
struct edge {
	int v;
	lol c, l;
};
 
struct sta {
	lol c;
	int v;
 
	bool operator < (const sta& rhs) const {
		return c > rhs.c;
	}
};
 
priority_queue<sta> pr;
vector<edge> v[MAX];
lol k, lef, rig, ans;
int n, m;
int vis[MAX];
 
void init() {
	ans = INF;
	lef = rig = 0;
	for (int i = 0; i < MAX; i++) v[i].clear();
}
 
bool test(lol t) {
	while (pr.size()) pr.pop();
	memset(vis, 0, sizeof(vis));
 
	pr.push((sta){0, 1});
	while (pr.size()) {
		
		auto ss = pr.top(); pr.pop();
		int now = ss.v;
		lol sum = ss.c;
 
		if (now == n) {
			// cout << t << ' ' << sum << endl;
			return (sum < k);
		}
		if (vis[now]) continue;
		vis[now] = 1;
 
		for (auto i : v[now]) {
			if (i.l > t) continue;
			if (vis[i.v]) continue;
 
			pr.push((sta){i.c + sum, i.v});
		}
	}
	return false;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		init();
 
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++) {
			int x, y; lol c, l;
			cin >> x >> y >> c >> l;
 
			v[x].push_back((edge){y, c, l});
			v[y].push_back((edge){x, c, l});
 
			rig = max(rig, l + 1);
		}
		lol mid;
		while (lef < rig) {
			mid = lef + (rig - lef) / 2;
 
			if (test(mid)) {
				ans = mid;
				rig = mid;
			} else {
				lef = mid + 1;
			}
		}
 
		if (ans == INF) 
			cout << -1 << '\n';
		else
			cout << ans << '\n';
 
	}
	return 0;
}
