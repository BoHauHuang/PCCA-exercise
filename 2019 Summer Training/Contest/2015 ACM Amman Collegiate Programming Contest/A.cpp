#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 1510
 
struct team {
    int ac, p;
    string nam;
 
    bool operator < (const team& rhs) const {
        if (ac != rhs.ac) return ac > rhs.ac;
        return p < rhs.p;
    }
} a[MAX];
 
int n;
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].nam >> a[i].ac >> a[i].p;
        }
        sort(a, a + n);
 
        cout << a[0].nam << '\n';
    }
    return 0;
}
