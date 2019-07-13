#include <bits/stdc++.h>
using namespace std;
#define MAX 110

int n, m, s[MAX];
queue<int> q;
vector<int> v[MAX];

void init() {
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) v[i].clear();
    while (q.size()) q.pop();
}

int main() {
    while (cin >> n >> m) {
        if (n + m == 0) break;

        init();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            s[y]++;
        }
        for (int i = 1; i <= n; i++) if (s[i] == 0) {
            q.push(i);
        } 

        while (q.size()) {
            int now = q.front(); q.pop();
            for (auto j : v[now]) {
                s[j]--;
                if (s[j] == 0) q.push(j);
            }
            cout << now << ' ';
        }
        cout << '\n';
    }
    return 0;
}
