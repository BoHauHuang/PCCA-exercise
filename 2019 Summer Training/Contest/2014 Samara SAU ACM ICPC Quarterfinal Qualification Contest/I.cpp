#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
 
int a[MAX][MAX], p[MAX];
int n, m, k, ans[MAX];
int vis[MAX];
 
void init() {
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < MAX; i++) p[i] = i;
}
 
int findset(int x) {
    return p[x] == x ? x : p[x] = findset(p[x]);
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();
 
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) if (!a[i][j]) {
            int x = findset(i);
            int y = findset(j);
            p[y] = x;
        }   
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) if (a[i][j]) {
            int x = findset(i);
            int y = findset(j);
 
            if (x == y) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    int now = 1;
    for (int i = 1; i <= n; i++) {
        int x = findset(i);
        if (!vis[x]) {
            vis[x] = now;
            now ++;
        }
        ans[i] = vis[x];
    }
    if (now > k + 1) {
        cout << -1 << '\n';
        return 0;
    }
 
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
 
    return 0;
}
