#include <bits/stdc++.h>
using namespace std;
#define MAX 510
 
struct stp {
	int x, y, s;
	int p;
 
	bool operator < (const stp& rhs) const {
		return s > rhs.s;
	}
};
 
priority_queue<stp> pr;
int n, m, a[MAX][MAX];
int c[2], ans;
int vis[MAX][MAX];
 
void init() {
	ans = -1;
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));
	while (pr.size()) pr.pop();
}
 
const int dx[5] = {0, 0, 0, 1, -1};
const int dy[5] = {0, 1, -1, 0, 0};
 
void solve() {
	pr.push((stp){1, 1, 0, 1});
 
	while (pr.size()) {
		stp now = pr.top(); pr.pop();
 
		if (now.x == n && now.y == m) {
			ans = now.s;
			return;
		}
 
		// cout << now.x << ' ' << now.y << endl;
 
		if (vis[now.x][now.y]) continue;
		
		vis[now.x][now.y] = 1;
		for (int i = 1; i <= 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
 
			if (nx > n || nx < 1) continue;
			if (ny > m || ny < 1) continue;
			if (!a[nx][ny] || vis[nx][ny]) continue;
 
			pr.push((stp){nx, ny, now.s + c[now.p], now.p ^ 1});
		}
	}
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	cin >> m >> n >> c[0] >> c[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char cc; cin >> cc;
			a[i][j] = (cc == '#' ? 0 : 1);
		}
	}
	solve();
 
	if (ans == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << '\n';
	return 0;
}
