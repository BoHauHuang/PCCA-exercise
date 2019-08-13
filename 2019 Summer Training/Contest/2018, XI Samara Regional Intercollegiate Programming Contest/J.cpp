#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
 
int a[MAX];
int ans = 0, n;
 
int main() {
    memset(a, 0, sizeof(a));
 
    cin >> n;
    while (n--) {
        int x; cin >> x;
        a[x] += 1;
    }
    for (int i = 1; i < MAX; i++) if (a[i] >= 2) {
        ans += a[i] / 2;
    }
    ans /= 2;
 
    cout << ans << '\n';
    return 0;
}
