#include <bits/stdc++.h>
using namespace std;
#define MAX 110
 
int n, m, ql, qr;
int ans[MAX];
int pre[MAX], suf[MAX], use[MAX];
 
void init() {
    memset(use, 0, sizeof(use));
    memset(ans, 0, sizeof(ans));
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
}
 
void getinfo(int t) {
    for (int i = 1; i <= n; i++) pre[i] = suf[i];
    memset(suf, 0, sizeof(suf));
 
    for (int i = 1; i <= t; i++) {
        int x; cin >> x;
        suf[x] = 1;
    }
}
 
int find_pre() {
    for (int i = 1; i <= n; i++) {
        if (pre[i] && !suf[i]) return i;
    }
    return -1;
}
 
int find_suf() {
    for (int i = 1; i <= n; i++) {
        if (!pre[i] && suf[i]) return i;
    }
    return -1;
}
 
void query(int xx, int yy) {
    cout << "Q " << xx << ' ' << yy << endl;
    getinfo(yy - xx + 1);
} 
 
void answer() {
    cout << "A";
    for (int i = 1; i <= n; i++) cout << ' ' << ans[i];
    cout << '\n';
}
 
int main() {
    init();
 
    cin >> n;
    m = (n + 1) / 2;
    
    ql = 1; qr = m;
    query(ql, qr);
    m --;
 
    while (m--) {
        ql += 1; qr += 1;
        query(ql, qr);
 
        ans[ql - 1] = find_pre();
        ans[qr] = find_suf();
 
        use[ans[ql - 1]] = 1;
        use[ans[qr]] = 1;
    }
 
    for (int j = 1; j <= n; j++) if (suf[j] && !use[j]) {
        ans[ql] = j;
        use[j] = 1;
        break;
    }
    for (int j = 1; j <= n; j++) if (!use[j]) {
        ans[n] = j;
        break;
    }
 
    answer();
    return 0;
}
