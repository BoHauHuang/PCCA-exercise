#include <bits/stdc++.h>
using namespace std;
#define MAX 55
 
bitset<MAX> vis;
int sg[MAX][MAX];
int n, k;
 
int getMex() {
	for (int i = 0; ; i++) if (!vis[i]) return i;
}
 
void build() {
	memset(sg, 0, sizeof(sg));
	
	for (int k = 1; k < MAX; k++) {
		for (int i = k; i < MAX; i++) {
			vis.reset();
			for (int j = 1; j + k - 1 <= i; j++) {
				int pre = j - 1;
				int suf = i - (j + k - 1);
 
				vis[sg[pre][k] ^ sg[suf][k]] = 1;
			}
			sg[i][k] = getMex();
		}
	}
}
 
int main() {
	build();
 
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n >> k;
		cout << "Case " << tt << ": " << (sg[n][k] ? "Winning" : "Losing") << '\n';
	}
	return 0;
}
