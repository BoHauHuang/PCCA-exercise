#include <bits/stdc++.h>
using namespace std;
#define MAX 50
 
struct poi {
    char c;
    int x, p;
 
    bool operator < (const poi& rhs) const {
        if (x != rhs.x) return x > rhs.x;
        return c > rhs.c; 
    }
} a[MAX];
 
int ans;
 
void init() {
    ans = 0;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 26; i++) {
        a[i].c = 'a' + i;
        a[i].x = 0;
        a[i].p = i;
    }
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
 
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
 
        string s;
        while (cin >> s) {
            if (s == "*") break;
 
            for (int i = 0; i < (int) s.length(); i++) {
                char now = tolower(s[i]);
                a[now - 'a'].x += 1;
            }
        }
        sort(a, a + 26);
        for (int i = 0; i < 5; i++) if (a[i].x != 0) ans += a[i].p;
 
 
        cout << "Case " << tt << ": " << (ans > 62 ? "Effective" : "Ineffective") << '\n';
    }
    return 0;
}
