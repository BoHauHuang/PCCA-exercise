#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<lol, lol> pii;
#define MAX 100010
 
struct cak {
    lol c, h;
 
    bool operator < (const cak& rhs) const {
        if (c != rhs.c) return c < rhs.c;
        return h > rhs.h;
    }
} a[MAX];
 
priority_queue<lol> pr;
int n, m;
lol ans_c, ans_h;
 
void init() {
    ans_c = ans_h = 0;
    memset(a, 0, sizeof(a));
    while (pr.size()) pr.pop();
}
 
int main() {
    ifstream cin("icecream.in");
 
    int t; cin >> t;
    while (t--) {
        init();
 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i].c;
        for (int j = 1; j <= n; j++) cin >> a[j].h;
        sort(a + 1, a + 1 + n);
 
        for (int i = 1; i <= m; i++) {
            ans_c = max(ans_c, a[i].c);
            ans_h += a[i].h;
 
            pr.push(-a[i].h);
        }
        for (int i = m + 1; i <= n && a[i].c == a[m].c; i++) {
            if (-pr.top() < a[i].h) {
                ans_h -= (-pr.top()); pr.pop();
                ans_h += a[i].h;
                
                pr.push(-a[i].h);
            }
        }
        cout << ans_c << ' ' << ans_h << '\n';
    }
    return 0;
}
