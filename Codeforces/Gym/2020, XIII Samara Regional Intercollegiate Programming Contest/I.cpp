#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 200010
 
int las[MAX];
int ok;
 
void init() {
	ok = 1;
	for (int i = 0; i < MAX; i++) las[i] = -INF;
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int now, col; cin >> now >> col;
 
		if (las[col] > now) ok = false;		
		las[col] = now;
	}
 
	cout << (ok ? "YES" : "NO") << '\n';
	return 0;
}
