#include <bits/stdc++.h>
using namespace std;
#define MAX 110
 
char c[MAX][MAX];
int ans[MAX][MAX], vis[MAX][MAX];
int n, m, sz;
 
struct sta {
	int x, y, s;
 
	bool operator < (const sta& rhs) const {
		return s > rhs.s;
	}
};
 
priority_queue<sta> pr;
 
void init() {
	sz = 0;
	while (pr.size()) pr.pop();
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
}
 
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};
 
void solve() {
	for (int i = 1; i <= n; i++) {
		pr.push((sta){i, 0});
		pr.push((sta){i, m + 1});
	}
	for (int i = 1; i <= m; i++) {
		pr.push((sta){0, i});
		pr.push((sta){n + 1, i});
	}
 
	while (pr.size()) {
		auto now = pr.top();  pr.pop();
 
		if (vis[now.x][now.y]) continue;
		vis[now.x][now.y] = 1;
		ans[now.x][now.y] = now.s;
		sz = max(sz, ans[now.x][now.y]);
 
		for (int i = 1; i <= 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
 
			if (nx < 1 || nx > n) continue;
			if (ny < 1 || ny > m) continue;
			if (vis[nx][ny]) continue;
 
			pr.push((sta){nx, ny, now.s + 1});
		}
	}
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
 
			if (c[i][j] == '.') pr.push((sta){i, j, 0});
		}
	}
	solve();
 
	if (sz == 0) sz = 1;
	else if (sz < 10) sz = 2;
	else
		sz = 3;
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
 
			if (c[i][j] == 'T') 
				cout << setw(sz) << setfill('.') << ans[i][j];
			else
				cout << setw(sz) << setfill('.') << "";
		}
		cout << '\n';
	}
 
	return 0;
}
