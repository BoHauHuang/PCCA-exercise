#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 1010
#define INF 0x3f3f3f3f
 
lol ans;
lol dp[MAX][MAX];
int n, m;
 
void init() {
    memset(dp, -INF, sizeof(dp));
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
 
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        cin >> n >> m;
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x; cin >> x;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + x;
            }
        }
        ans = dp[n][m];
 
        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
