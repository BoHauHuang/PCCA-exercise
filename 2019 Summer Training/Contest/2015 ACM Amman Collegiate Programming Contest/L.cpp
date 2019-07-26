#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MAX 100010
 
int n, k;
int dp[MAX], a[MAX];
int ql, qr, mod;
pair<int, int> p[MAX * 4];
vector<int> v; 
 
void modify(int x, int y, int now) {
    if (x == y) {
        p[now].F = mod;
        p[now].S = x;
        return;
    }
    
    int m = x + (y - x) / 2, ls = now * 2, rs = now * 2 + 1;
    if (ql <= m) modify(x, m, ls);
    if (m  < ql) modify(m + 1, y, rs);
 
    if (p[ls].F < p[rs].F) swap(ls, rs);
 
    p[now].F = p[rs].F;
    p[now].S = p[rs].S;
}
 
pair<int, int> query(int x, int y, int now) {
    if (ql <= x && y <= qr) return p[now];
 
    int m = x + (y - x) / 2, ls = now * 2, rs = now * 2 + 1;
    pair<int, int> ll = make_pair(INF, x), rr = make_pair(INF, y);
 
    if (ql <= m) ll = query(x, m, now * 2);
    if (m  < qr) rr = query(m + 1, y, now * 2 + 1);
 
    if (ll.F < rr.F) return ll;
    return rr;
}

void init() {
    v.clear();
    memset( a,  -1, sizeof( a));
    memset( p, INF, sizeof( p));
    memset(dp, INF, sizeof(dp));
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
 
    int t; cin >> t;
    while (t--) {
        init();
 
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            a[i] = c - '0';

            if (a[i] == a[i - 1]) v.push_back(i);
        }
 
        dp[n + 1] = 0;
        ql = n + 1;
        mod = 0;
        modify(1, n + 1, 1);

        for (int i = n; i >= 1; i--) {
            int ok = 0;
            if (v.size() && v[v.size() - 1] > i) {
                ok = 1;
                ql = (*upper_bound(v.begin(), v.end(), i));
            }
            ql += 1;
            qr = min(i + k, n + 1);
 
            if (i < ql && ql <= qr && ok) {
                dp[i] = dp[query(1, n + 1, 1).S] + 1;
            }
            dp[i] = min(dp[i + 1] + 1, dp[i]);
            
            ql = i;
            mod = dp[i];
            modify(1, n + 1, 1);
        }

        cout << dp[1] - 1 << '\n';
    }
    return 0;
}
