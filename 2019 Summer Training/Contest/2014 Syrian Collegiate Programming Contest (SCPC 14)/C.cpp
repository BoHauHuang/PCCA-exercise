#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 10010
 
lol ans;
lol a[MAX];
vector<pair<int, int> > v;
int n, m, c;
 
void init() {
    ans = 0;
    v.clear();
    memset(a,  0, sizeof(a));
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
 
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        cin >> n >> m >> c;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[x] += 1;
        }
        for (int i = 1; i <= m; i++) {
            v.push_back(make_pair(a[i], i));
        }
        sort(v.begin(), v.end());
        
        lol sum = 0;
        for (int i = m - 1; i >= 0; i--) {
            lol now = v[i].second * v[i].second % c;
            sum += now;
 
            ans = max(ans, sum * v[i].first);
        }
 
        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
