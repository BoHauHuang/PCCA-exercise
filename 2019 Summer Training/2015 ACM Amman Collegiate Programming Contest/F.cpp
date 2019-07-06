#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
 
struct edge{
    int x, y, c;
 
    bool operator < (const edge& rhs) const {
        return c < rhs.c;
    }
};
 
vector<edge> v;
int n, m, ans;
int p[MAX];
 
int findset(int x) {
    return p[x] == x ? x : p[x] = findset(p[x]);
}
 
void init() {
    for (int i = 0; i < MAX; i++) p[i] = i;
    v.clear();
    ans = 0;
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        init();
        
        cin >> n >> m;
        while (m--) {
            int x, y, c; 
            cin >> x >> y >> c;
            v.push_back((edge){x, y, c});
        }
        sort(v.begin(), v.end());
 
        for (auto i : v) {
            int x = findset(i.x);
            int y = findset(i.y);
            if (x != y) {
                p[x] = y;
                ans = max(ans, i.c);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
