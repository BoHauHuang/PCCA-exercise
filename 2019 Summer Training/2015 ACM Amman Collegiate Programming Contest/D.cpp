#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10010
 
int n, k;
int dp[MAX], a[MAX];
 
bool chk(int x, int y) {
    if (x == y) return true;
    for (int i = x + 1; i <= min(y, n); i++) {
        if (a[i] == a[i - 1]) return true;
    }
    return false;
}
 
void init() {
    memset(dp, INF, sizeof(dp));
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        init();
 
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            a[i] = c - '0';
        }
 
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int ok = 0;
            for (int j = i - 1; j >= max(1, i - k + 1); j--) {
                if (ok || chk(j, i)) {
                    ok = 1;
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        cout << dp[n] - 1 << '\n';
    }
    return 0;
}
