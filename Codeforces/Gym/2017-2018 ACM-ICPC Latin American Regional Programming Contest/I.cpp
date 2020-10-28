#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int, int> pii;
#define F first
#define S second
#define MAX 100010
 
const int MAX_LOG = log2(MAX) + 5;
 
struct edge {
	int x, y;
	lol c;
 
	bool operator < (const edge& rhs) const {
		return c < rhs.c;
	}
};
 
map<pii, int> mp, egs;
vector<edge> all_edge;
vector<pii> v[MAX];
int n, m, p[MAX], LOG, lev[MAX];
int par[MAX][MAX_LOG];
lol dir[MAX][MAX_LOG];
lol ans_mst;
 
void init() {
	mp.clear();
	egs.clear();
	ans_mst = 0;
	all_edge.clear();
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
		v[i].clear();
	}
	memset(par, 0, sizeof(par));
	memset(dir, 0, sizeof(dir));
	memset(lev, 0, sizeof(lev));
}
 
int findset(int x) {
	return p[x] == x ? x : (p[x] = findset(p[x]));
}
 
void MST() {
	sort(all_edge.begin(), all_edge.end());
	
	for (auto i : all_edge) {
		int x = findset(i.x), y = findset(i.y);
 
		if (x != y) {
			p[y] = x;
			ans_mst += i.c;
 
			v[i.x].push_back(make_pair(i.y, i.c));
			v[i.y].push_back(make_pair(i.x, i.c));
 
			egs[make_pair(i.x, i.y)] = 1;
			egs[make_pair(i.y, i.x)] = 1;
			// cout << "add " << i.x << ' ' << i.y << ' ' << endl;
		}
	}
}
 
void dfs(int now, int pre, int dep) {
	lev[now] = dep;
 
	for (auto i : v[now]) if (i.F != pre) {
		par[i.F][0] = now;
		dir[i.F][0] = i.S;
 
		dfs(i.F, now, dep + 1);
	}
}
 
void build() {
	dfs(1, -1, 1);
 
	LOG = log2(n) + 1;
 
	// cout << MAX_LOG << ' ' << LOG << endl;
	// return;
 
	for (int j = 1; j <= LOG; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			dir[i][j] = max(dir[par[i][j - 1]][j - 1], dir[i][j - 1]);
		}
	}
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; lol c;
		cin >> x >> y >> c;
 
		mp[make_pair(x, y)] = c;
		mp[make_pair(y, x)] = c;
		all_edge.push_back((edge){x, y, c});
	}
	MST();
 
	build();
 
	int q; cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		if (egs.find(make_pair(x, y)) != egs.end()) {
			cout << ans_mst << '\n';
			continue;
		}
 
		lol ans_cyc = 0, now_edg = mp[make_pair(x, y)];
		
		if (lev[x] < lev[y]) swap(x, y);
		for (int j = LOG; j >= 0; j--) {
			if (lev[par[x][j]] >= lev[y]) {
				ans_cyc = max(ans_cyc, dir[x][j]);
				x = par[x][j];
			}
			if (lev[x] == lev[y]) break;
		}
		if (x != y) {
			for (int j = LOG; j >= 0; j--) {
				if (par[x][j] != par[y][j]) {
					ans_cyc = max(ans_cyc, dir[x][j]);
					ans_cyc = max(ans_cyc, dir[y][j]);
 
					x = par[x][j];
					y = par[y][j];
				}
			}
			ans_cyc = max(ans_cyc, max(dir[x][0], dir[y][0]));
		}
		// cout << "LCA = " << x << ", ans_cyc = " << ans_cyc << endl;
 
		cout << ans_mst - ans_cyc + now_edg << '\n'; 
	}
	// cout << "MST " << ans_mst << '\n';
 
	return 0;
}
