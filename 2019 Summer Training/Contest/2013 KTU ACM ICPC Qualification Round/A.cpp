#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    for (int k = 1; k <= t; k++) {
        int n; cin >> n;
        for (int i = 1; i <= n - 1; i++) {
            int x, y; cin >> x >> y;
        }
 
        cout << "Case #" << k << ": " << (n == 1 ? 1 : 2) << '\n';
    }
    return 0;
}
