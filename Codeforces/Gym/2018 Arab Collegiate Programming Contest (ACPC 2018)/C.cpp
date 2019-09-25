#include <bits/stdc++.h>
using namespace std;
 
int n, m;
map<string, int> mp[4];
 
int main() {
	// cin.tie(0), cout.sync_with_stdio(false);
	
	ifstream ccs("coffee.in");
	
	int t; ccs >> t;
	while (t--) {
		ccs >> n >> m;
		
		int x, y, z;
		string nam, siz, typ; 
		for (int i = 1; i <= n; i++) {
			ccs >> nam >> x >> y >> z;
			
			mp[0][nam] = x;
			mp[1][nam] = y;
			mp[2][nam] = z;
		}
		int fee = 100 / m;
		for (int i = 1; i <= m; i++) {
			ccs >> nam >> siz >> typ;
			
			int now = fee;
			if (siz[0] == 's') {
				now += mp[0][typ];
			}
			if (siz[0] == 'm') {
				now += mp[1][typ];
			}
			if (siz[0] == 'l') {
				now += mp[2][typ];
			}
			if (now % 10 == 4) now += 1;
			if (now % 10 == 6) now -= 1;
			if (now % 10 == 9) now += 1;
			if (now % 10 == 1) now -= 1;
			
			cout << nam << ' ' << now << '\n';
		}
	}
	return 0;
}
