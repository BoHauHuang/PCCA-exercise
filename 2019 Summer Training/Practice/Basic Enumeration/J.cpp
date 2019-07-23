#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 20

int n, a[MAX];
int low, upp, dis, ans = 0;

int main() {
    cin >> n >> low >> upp >> dis;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 1; i <= (1 << n); i++) {
        int sum = 0, cnt = 0, big = -INF, sml = INF;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            sum += a[j];
            cnt += 1;
            sml = min(sml, a[j]);
            big = max(big, a[j]);
        }
        if (cnt >= 2 && low <= sum && sum <= upp && big - sml >= dis) {
            ans += 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
