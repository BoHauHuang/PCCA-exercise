#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
 
lol xx, yy = 10000000000000008, m, ans;
lol cnt1, cnt2, x, y, tc1, tc2;
 
bool check(lol m) {
	lol c1 = (m/y)-(m/(x*y)); 
	lol c2 = (m/x)-(m/(x*y));
	lol remain = m-c1-c2-(m/(x*y));
	
	if(c1 >= tc1) tc1 = 0;
	else tc1 -= c1;
	if(c2 >= tc2) tc2 = 0;
	else tc2 -= c2;
	
	if(tc1+tc2 <= remain) return 1;
	else return 0;
}
 
int main() {
	cin >> cnt1 >> cnt2 >> x >> y;
	
	while (xx < yy) {
		m = xx + (yy - xx) / 2;
 		tc1 = cnt1;
		tc2 = cnt2;
		if (check(m)) {
			ans = m;
			yy = m;
		} else 
			xx = m + 1;
	}
	cout << ans << '\n';
	return 0;
}
