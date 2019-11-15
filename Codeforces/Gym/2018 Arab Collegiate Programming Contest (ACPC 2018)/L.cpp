#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MAXM 21
#define MOT 30
 
int n, m;
int a[MAX], ans[MOT];
vector<int> v[MOT];
set<int> s;
 
void init() {
    s.clear();
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < MOT; i++) v[i].clear();
}
 
int cal(int x) {
    int cnt = 0, t = 1;
    for (int j = 0; j < MOT; j++) {
        if (x % 2 && !ans[j]) cnt += t;
        x /= 2;
        t *= 2;
    }
    return cnt;
}
 
void add(int x) {
    int cnt = 0;
    for (int j = 0; j < MOT; j++) {
        if (x % 2) ans[j] = 1;
        x /= 2;
    }
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    ifstream cin("looking.in");
 
    int t; cin >> t;
    while (t--) {
        init();
 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
 
            int x = a[i];
            for (int j = 0; j < MOT; j++) {
                if (x % 2) v[j].push_back(i);
                x /= 2;
            }
        }
 
        for (int i = MOT - 1; i >= 0 && m; i--) if (v[i].size() && !ans[i]) {
            int now = 0, poi = 0;
            for (auto j : v[i]) {
                if (s.count(j)) continue;
 
                int tmp = cal(a[j]);
                if (tmp > now) {
                    now = tmp;
                    poi = j;
                }
                add(a[j]);
                s.insert(j);
            }
        }
        int num = 0, t = 1;
        for (int i = 0; i < MOT; i++) {
            if (ans[i]) num += t;
            t *= 2;
        }
        cout << num << '\n';
    }
    return 0;
}
