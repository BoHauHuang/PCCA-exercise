#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int , int> pii;
#define INF 0x3f3f3f3f
#define MAX 110

char pic[MAX][MAX];
int m, n, idx[MAX][MAX];

void init() {
    memset(idx, 0, sizeof(idx));
    memset(pic, 0, sizeof(pic));
}

void dfs(int r, int c, int id) {
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    if(idx[r][c] > 0 || pic[r][c] != '@') return;
    
    idx[r][c] = id;
    for(int dr = -1; dr <= 1; dr++) {
        for(int dc = -1; dc <= 1; dc++) {
            if(dr != 0 || dc != 0) dfs(r + dr, c + dc, id);
        }
    }
}

int main() {
    while (cin >> m >> n && m && n) {
        init();
        for(int i = 0; i < m; i++) cin >> pic[i];
        
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
