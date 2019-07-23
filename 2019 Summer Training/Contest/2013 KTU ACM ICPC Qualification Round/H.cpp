#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
 
int n, m, p[MAX];
int s[MAX];
 
void init() {
    for (int i = 0; i < MAX; i++) {
        p[i] = i;
        s[i] = 1;
    }
}
 
int findset(int x) {
    return x == p[x] ? x : p[x] = findset(p[x]);
}
 
int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int x, y; cin >> x >> y;
 
            x = findset(x);
            y = findset(y);
 
            if (x != y) {
                if (s[x] < s[y]) swap(x, y);
                p[y] = x;
                s[x] += s[y];
            }
        }
 
        cout << "Case #" << tt << ":\n";
        for (int i = 1; i <= n; i++) {
            cout << s[findset(i)] - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
