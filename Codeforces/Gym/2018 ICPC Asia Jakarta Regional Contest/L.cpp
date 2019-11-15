#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 110
 
lol n;
int a[MAX], b[MAX], ans;
string s;
 
void init() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    ans = 0;
}
 
int main() {
    init();
 
    cin >> n >> s;
 
    int p = 0;
    while (n) {
        a[p] = n % 2;
        n /= 2;
        p += 1;
    }
    ans = (int) s.length() - p;
 
    if (ans < 0) {
        cout << 0 << '\n';
        return 0;
    }
 
    int k = (int) s.length() - p, t = p - 1, c = 0;
    for (int i = 1; i < s.length(); i++) if (s[i] == '1') c += 1;
    for (int i = 0; i < s.length(); i++) {
        if (i != 0 && k && s[i] == '1') {
            k--;
            c--;
            continue;
        }
        if (c < k) {
            k --;
            continue;
        }
 
        b[t] = s[i] - '0';
        t -= 1;
    }
    for (int i = p - 1; i >= 0; i--) {
        if (b[i] > a[i]) {
            ans ++;
            break;
        }
        if (a[i] > b[i]) {
            break;
        }
    }
 
    cout << ans << '\n';
    return 0;
}
