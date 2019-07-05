#include <bits/stdc++.h>
using namespace std;

int n, ans;
char c[110];

void init() {
    ans = 0;
    memset(c, 0, sizeof(c));
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        init();

        cin >> n;
        for (int i = 1; i <= n; i++) cin >> c[i];

        for (int i = 1; i <= n; i++) {
            if (c[i] == '.') {
                ans ++;
                i += 2;
            }
        }

        cout << "Case " << cas << ": " << ans << '\n';
    }
    return 0;
}
