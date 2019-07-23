#include <bits/stdc++.h>
using namespace std;
#define MAX 1100
 
int n, a[MAX];
int ans, mot;
 
void init() {
    ans = 0;
    mot = 0;
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        init();
 
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mot = max(mot, a[i]);
        }
        int t = 100 - mot;
        for (int i = 1; i <= n; i++) {
            a[i] += t;
            if (a[i] >= 50) ans ++;
        }
        cout << ans << '\n';
    }
 
    return 0;
}
