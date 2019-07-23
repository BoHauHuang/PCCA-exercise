#include <bits/stdc++.h>
using namespace std;
#define MAX 10010

int n, dp[MAX][2];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    while (cin >> n && n) {
        init();

        for (int i = 1; i <= n; i++) {
            cin >> dp[i][1];

            dp[i][1] = max(dp[i - 1][1] + dp[i][1], dp[i][1]);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        int ans = max(dp[n][1], dp[n][0]);
        if (ans > 0)
            cout << "The maximum winning streak is " << ans << ".\n";
        else
            cout << "Losing streak.\n";
    }
    return 0;
}
