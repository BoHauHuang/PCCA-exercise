#include<bits/stdc++.h>
#define MAX 200000
using namespace std;
vector<int> v[MAX];
int MAX_LOG;
int dep[MAX];
int par[(int)log2(MAX)+1][MAX];
int n, q;
 
void init() {
    for (int i = 1; i <= n; i++) v[i].clear();
    memset(dep, 0, sizeof(dep));
    memset(par, 0, sizeof(par));
    MAX_LOG = log2(n) + 1;
}
 
void dfs(int now, int fa, int d) {
    par[0][now] = fa;
    dep[now] = d;
 
    for (int i = 0; i < v[now].size(); i++) {
        if (v[now][i] != fa) dfs(v[now][i], now, d + 1);
    }
}
 
void build() {
    dfs(1, -1, 0);
 
    for (int i = 0; i < MAX_LOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i][j] <= 0) 
                par[i + 1][j] = -1;
            else 
                par[i + 1][j] = par[i][par[i][j]];
        }
    }
}
 
int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0; i < MAX_LOG; i++) {
        if ((dep[x] - dep[y]) >> i & 1) {
            y = par[i][y];
        }
    }
 
    if (x == y) return x;
 
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (par[i][x] != par[i][y]) {
            x = par[i][x];
            y = par[i][y];
        }
    }
    return par[0][x];
}
 
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	ifstream cin("dynamic.in");
	ofstream cout("dynamic.out");
	while(cin >> n && n){
		int a, b;
		init();
		for(int i = 0 ; i < n-1 ; i++){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		build();
	
		int m, root_now = 1;
		cin >> m;
		while(m--){
			char cmd;
			cin >> cmd;
			if(cmd == '?'){
				cin >> a >> b;
				int ar = lca(a, root_now), br = lca(b, root_now), lcar = lca(lca(a, b), root_now);
				if(ar == root_now && br == root_now && lcar == root_now) cout << lca(a, b) << '\n';
				else{
					if(lca(a, b) == lca(a, root_now)) cout << lca(b,root_now) << '\n';
					else if(lca(a, b) == lca(b, root_now)) cout << lca(a, root_now) << '\n';
					else cout << lca(a, b) << '\n';
				}
			}
			else if(cmd == '!'){
				cin >> a;
				root_now = a;
			}
		}
	}
}
