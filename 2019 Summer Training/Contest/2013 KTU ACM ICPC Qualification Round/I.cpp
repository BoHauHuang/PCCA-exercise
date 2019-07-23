#include<bits/stdc++.h>
using namespace std;
#define MAX 20
 
string a[MAX];
int n, m;
 
int finddif(string x, string y) {
    int dif = 0;
    if (x.length() != y.length()) return 100;
 
    for (int i = 0; i < (int) x.length(); i++) {
        if (x[i] != y[i]) dif ++;
    }
    return dif;
}
 
int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ":\n";
 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            string now; cin >> now;
            int ok = 0, cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (now == a[j]) {
                    cout << "yes\n";
                    ok = true;
                    break;
                }
            }
            if (ok) continue;
            for (int j = 1; j <= n; j++) {
                if (finddif(now, a[j]) == 1) cnt ++;
            }
            if (cnt == 1) {
                cout << "yes\n";
                continue;
            }
            cout << "no\n";
        }
    }
    return 0;
}
close
