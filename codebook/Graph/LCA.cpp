#define MAX 200000
vector<int> v[MAX];
int MAX_LOG, dep[MAX], par[(int)log2(MAX)+1][MAX], n,q;
 
void init() {
    for (int i = 1; i <= n; i++) v[i].clear();
    memset(dep, 0, sizeof(dep));
    memset(par, 0, sizeof(par));
    MAX_LOG = log2(n) + 1;
}
 
void dfs(int now, int fa, int d) {
    par[0][now] = fa, dep[now] = d;
    for (int i = 0; i < v[now].size(); i++) 
        if (v[now][i] != fa) dfs(v[now][i], now, d + 1);
}
 
void build() {
    dfs(1, -1, 0);
 
    for (int i = 0; i < MAX_LOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i][j] <= 0) par[i + 1][j] = -1;
            else par[i + 1][j] = par[i][par[i][j]];
        }
    }
}
 
int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0; i < MAX_LOG; i++) 
        if ((dep[x] - dep[y]) >> i & 1) y = par[i][y];
 
    if (x == y) return x;
 
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (par[i][x] != par[i][y]) x = par[i][x], y = par[i][y];
    
    return par[0][x];
}
