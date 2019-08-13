#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
 
string a, b;
int n;
 
int main() {
    
    cin >> a >> b;
    n = (int) a.length();
 
    int sta = -1, bac = -1;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) {
        sta = i;
        break;
    }
    for (int i = n - 1; i >= 0; i--) if (a[i] != b[i]) {
        bac = i;
        break;
    }
    if (a == b) {
        cout << "YES\n";
        return 0;
    }
    if (sta == -1 || bac == -1) {
        cout << "NO\n";
        return 0;
    }
 
    int x = sta, y = bac;
    while (a[x] == b[y]) {
        x ++;
        y --;
 
        if (x > bac || y < sta) break;
    }
    if (x <= bac || y >= sta) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    
    return 0;
}
