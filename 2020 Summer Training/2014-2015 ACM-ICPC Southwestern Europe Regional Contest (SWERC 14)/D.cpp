#include <bits/stdc++.h>
using namespace std;
#define MAX 20010
#define MAXN 10000
 
int n, m, ans;
int vis[MAX], res[MAX];
vector<int> v[MAX];
 
void init() {
	memset(vis, 0, sizeof(vis));
	memset(res, 0, sizeof(res));
}
 
bool dfs(int now) {
	for (auto i : v[now]) if (!vis[i]) {
		vis[i] = 1;
 
		if (res[i] == 0 || dfs(res[i])) {
			res[now] = i;
			res[i] = now;
			// cout << now << ' ' << i << endl;
			return true;
		}
	}
	return false;
}
 
bool bip() {
	int c = 0;
	for (int i = 1; i <= n; i++) if (res[i] == 0) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) c++;
 
		// cout << "ite " << i << '\n';
		// for (int j = 1; j <= n; j++) cout << j << " : " << res[j] << '\n';
		// cout << '\n';
	}
	return (c == n);
}
 
int main() {
	init();
 
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		x += 1; y += 1;
 
		// cout << x << ' ' << y + MAXN << endl;
		v[x].push_back(y + MAXN);
		v[y + MAXN].push_back(x);
	}
	// for (int j = 1; j <= n; j++) cout << res[j] << ' '; cout << endl;
 
	ans = bip();
 
	cout << (ans ? "YES" : "NO") << '\n';
	return 0;
}
