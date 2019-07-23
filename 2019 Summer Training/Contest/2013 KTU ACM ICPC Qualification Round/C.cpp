#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
 
struct poi {
    int a[30];
    int sot;
 
    void clear() {
        sot = 0;
        memset(a, 0, sizeof(a));
    }
 
    poi operator + (poi rhs) {
        poi now; now.clear();
        for (int i = 1; i <= 26; i++) {
            now.a[i] = (this -> a[i]) + rhs.a[i];
        }
        return now;
    }
} p[MAX * 4];
 
int n, m, ql, qr;
poi in[MAX], qur;
string s;
 
void init() {
    qur.clear();
    memset( p, 0, sizeof( p));
    memset(in, 0, sizeof(in));
}
 
void build(int x, int y, int now) {
    if (x == y) {
        p[now] = in[x];
        p[now].sot = 0;
        return;
    }
 
    int m = x + (y - x) / 2;
    build(x, m, now * 2);
    build(m + 1 , y, now * 2 + 1);
 
    p[now].sot = 0;
    p[now] = p[now * 2] + p[now * 2 + 1];
}
 
void pushdown(int x, int y, int now) {
    if (!p[now].sot) return;
 
    int m = x + (y - x) / 2, ls = now * 2, rs = now * 2 + 1;
    int l = m - x + 1;
    poi tmp = p[now];
    p[ls].clear();
    p[rs].clear();
 
    int k = 0;
    while (l) {
        k ++;
        p[ls].a[k] = min(l, tmp.a[k]);
        tmp.a[k] -= p[ls].a[k];
        l -= p[ls].a[k];
    }
    p[rs] = tmp;
 
    p[now].sot = 0;
    p[ls].sot = 1;
    p[rs].sot = 1;
}
 
poi query(int x, int y, int now) {
    if (ql <= x && y <= qr) return p[now];
    pushdown(x, y, now);
 
    int m = x + (y - x) / 2;
    poi lef, rig; 
    lef.clear(); 
    rig.clear();
    
    if (ql <= m) lef = query(x, m, now * 2);
    if (m  < qr) rig = query(m + 1, y, now * 2 + 1);
 
    return lef + rig;
}
 
void modify(int x, int y, int now) {
    if (ql <= x && y <= qr) {
        p[now].clear();
 
        int lef = y - x + 1, k = 0;
        while (lef) {
            k ++;
            
            p[now].a[k] = min(lef, qur.a[k]);
            qur.a[k] -= p[now].a[k];
            lef -= p[now].a[k];
        }
        p[now].sot = 1;
        return;
    }
    pushdown(x, y, now);
 
    int m = x + (y - x) / 2;
    if (ql <= m) modify(x, m, now * 2);
    if (m  < qr) modify(m + 1, y, now * 2 + 1);
 
    p[now] = p[now * 2] + p[now * 2 + 1];
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
 
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        init();
        
        cout << "Case #" << tt << ":\n";
 
        cin >> s;
        n = (int) s.length();
        for (int i = 1; i <= n; i++) in[i].a[s[i - 1] - 'A' + 1] = 1;
        build(1, n, 1);
 
        cin >> m;
        char ope;
        for (int i = 1; i <= m; i++) {
            cin >> ope >> ql >> qr;
            ql += 1; 
            qr += 1;
            
            if (ope == 'g') {
                qur = query(1, n, 1);
                for (int i = 1; i <= 26; i++) cout << qur.a[i] << ' ';
                cout << '\n';
            }
            if (ope == 's') {
                qur = query(1, n, 1);
                modify(1, n, 1);
            }
        }      
    }
    return 0;
}

