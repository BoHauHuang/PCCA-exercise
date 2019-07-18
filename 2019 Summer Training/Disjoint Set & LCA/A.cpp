#include <bits/stdc++.h>
using namespace std;
#define MAX 30010

int p[MAX], n, m, ans;
int s[MAX];

int findset(int x) {
    return p[x] == x ? x : p[x] = findset(p[x]);
}

void init() {
    for (int i = 0; i < MAX; i++) {
        p[i] = i;
        s[i] = 1;
    }
    ans = 1;
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        init();

        cin >> n >> m;
        while (m--) {
            int x, y; cin >> x >> y;
            x = findset(x);
            y = findset(y);

            if (x != y) {
                if (s[x] > s[y]) swap(x, y);

                p[x] = y;
                s[y] += s[x];

                ans = max(ans, s[y]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
