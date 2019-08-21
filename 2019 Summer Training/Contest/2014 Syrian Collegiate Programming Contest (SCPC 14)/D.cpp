#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 100010
#define INF 0x3f3f3f3f
 
lol ans;
lol a[MAX];
int n, m, d;
 
void init() {
    ans = INF;
    a[0] = 0;
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        cin >> n >> m >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
 
        for (int i = 0; i <= n; i++) {
            ans = min(ans, a[i] * i * d + m * (n - i));
        }
 
        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
