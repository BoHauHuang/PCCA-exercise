#include <bits/stdc++.h>
using namespace std;
#define MAX 110
 
int n, a[MAX];
set<pair<int, pair<int, int> > > s; 
 
void init() {
    s.clear();
    memset(a, 0, sizeof(a));
}
 
bool chk(int x, int y, int z) {
    if (x + y < z) return false;
    if (z - y >= x) return false;
    return true; 
}
 
int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
 
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (chk(a[i], a[j], a[k])) s.insert(make_pair(a[i], make_pair(a[j], a[k])));
                }
            }
        }
        cout << "Case #" << tt << ": " << s.size() << '\n';
    }
    return 0;
}
