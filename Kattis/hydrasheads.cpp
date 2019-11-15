#include<bits/stdc++.h>
using namespace std;

int main(){
	int h, t, ans;
	while (cin >> h >> t) {
		if (h == t == 0) break;
		ans = 0;

		if (t % 2) { ans += 1; t += 1; }
		
		int k = t / 2;
		ans += k; h += k;

		if (h % 2) {
			ans += 3;
			h += 1;
		}
		ans += h / 2;

		cout << ans << '\n';
	}
	
	return 0;
}
