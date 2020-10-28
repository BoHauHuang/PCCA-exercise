#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int, int> pii;
typedef pair<int, lol> pil;
#define MAX 100010
 
struct peo {
	int rich, pret;
	lol mony;
 
	bool operator < (const peo& rhs) const {
		if (rich == rhs.rich) return pret < rhs.pret;
		return rich < rhs.rich;
	}
 
	void update(int r, int p, lol m) {
		this -> rich = r;
		this -> pret = p;
		this -> mony += m;
	}
 
} a[MAX];
 
int n, ql, qr, nn;
lol ans, p[MAX * 4], mod;
vector<int> all;
vector<pil> all_mod;
map<pii, int> mp;
 
void init() {
	n = 0;
	ans = 0;
	all.clear();
	memset(a, 0, sizeof(a));
}
 
void update(int x, int y, int now) {
	if (x == y) {
		p[now] = max(mod, p[now]);
		return;
	}
 
	int m = x + (y - x) / 2;
	if (ql <= m) update(x, m, now * 2);
	if (m  < ql) update(m + 1, y, now * 2 + 1);
 
	p[now] = max(p[now * 2], p[now * 2 + 1]);
}
 
lol query(int x, int y, int now) {
	if (ql <= x && y <= qr) return p[now];
 
	lol ll = 0, rr = 0;
	int m = x + (y - x) / 2;
	if (ql <= m) ll = query(x, m, now * 2);
	if (m  < qr) rr = query(m + 1, y, now * 2 + 1);
 
	return max(ll, rr);
}
 
void discrete() {
	sort(all.begin(), all.end());
 
	nn = (int) (unique(all.begin(), all.end()) - all.begin());
	all.resize(nn);
}
 
void solve() {
	discrete();
 
	sort(a + 1, a + 1 + n);
 
	all_mod.clear();
	for (int i = 1; i <= n; i++) {
		ql = 1;
		qr = (int) (lower_bound(all.begin(), all.end(), a[i].pret) - all.begin());
		
		// cout << a[i].rich << ' ' << a[i].pret << ' ' << a[i].mony << ' ';
		// cout << ql << ' ' << qr << '\n';
 
		lol tmp = 0;
		if (ql <= qr) tmp = query(1, nn, 1);
		
		// cout << "Push " << qr + 1 << ' ' << tmp + a[i].mony << endl;
 
		all_mod.push_back(make_pair(qr + 1, tmp + a[i].mony));
 
		if (a[i].rich != a[i + 1].rich) {
			for (auto j : all_mod) {
				ql = j.first;
				mod = j.second;
 
				// cout << "MOD " << ql << ' ' << mod << '\n';
				update(1, nn, 1);			
			}
			all_mod.clear();
		}
	}
	ans = p[1];
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int r, p; lol m;
 
		cin >> r >> p >> m;
		pii now = make_pair(r, p);
		
		if (mp.find(now) == mp.end()) mp[now] = ++n;
		a[mp[now]].update(r, p, m);
 
		all.push_back(p);
	}
	solve();
 
	cout << ans << '\n';
	return 0;
}
