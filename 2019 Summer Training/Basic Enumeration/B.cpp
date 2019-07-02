#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 15

int use[MAX];
vector<string> v;

void dfs(string now, int len) {
    if (len == 5) {
        v.push_back(now);
        return;
    }
    for (int i = 0; i <= 9; i++) if (!use[i]) {
        string nxt = now;
        nxt += (i + '0');
        use[i] = 1;
        
        dfs(nxt, len + 1);
        
        use[i] = 0;
    }
}

void build() {
    memset(use, 0, sizeof(use));
    dfs("", 0);
}

bool che(int a, string b) {
    memset(use, 0, sizeof(use));
    
    int cnt = 0;
    while (a) {
        if (use[a % 10]) return false;
        use[a % 10]++;
        a /= 10;
        cnt++;
    }
    if (cnt == 4) {
        if (use[0]) return false;
        use[0]++;
    }
    for (int i = 0; i < b.length(); i++) {
        if (use[b[i] - '0']) return false;
        use[b[i] - '0']++;
    }
    return true;
}

int main() {
    build();
    int n, cnt = 0;
    while (cin >> n && n) {
        if (cnt) cout << '\n';
        bool ok = false;

        for (auto i : v) {
            int x = stoi(i);
            if (che(n * x, i)) {
                cout << n * x << " / " << i << " = " << n << '\n';
                ok = true;
            }
        }
        if (!ok) cout << "There are no solutions for " << n << ".\n";
        cnt++;
    }
    return 0;
}
