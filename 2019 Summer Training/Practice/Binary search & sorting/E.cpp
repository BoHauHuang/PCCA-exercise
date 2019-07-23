#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 100010

int n, m;
int vis[MAX];
lol a[MAX];

bool check(lol p) {
    memset(vis, 0, sizeof(vis));

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;

        cnt += 1;
        lol now = a[i] + p;
        while (i < n && a[i + 1] <= now + p) {
            i++ ;
            vis[i] = 1;
        }
    }
    return cnt <= m;
}


int main() {
    cin.tie(0), cout.sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] *= 10;
        }
        sort(a + 1, a + 1 + n);
        
        lol x = 0, y = a[n], ans = -1;
        while (x < y) {
            lol m = x + (y - x) / 2;
            if (check(m)) {
                ans = m;
                y = m;
            } else 
                x = m + 1;
        }
        cout << ans / 10 << "." << ans % 10 << '\n';
    }
    return 0;
}
