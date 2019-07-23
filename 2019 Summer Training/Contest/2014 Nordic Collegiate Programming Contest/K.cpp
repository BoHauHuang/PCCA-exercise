#include <bits/stdc++.h>
using namespace std;
 
int c, n;
int now, ok;
int x, y, z;
 
void init() {
    now = 0;
    ok = true;
}
 
int main() {
    init();
 
    cin >> c >> n;
    while (n--) {
        cin >> x >> y >> z;
 
        if (x > now) ok = false;
        now -= x;
        now += y;
        if (now > c) ok = false;
        if (now != c && z) ok = false;
    }
    if (now || z) ok = false;
 
    cout << (ok ? "possible" : "impossible") << '\n';
    return 0;
}
