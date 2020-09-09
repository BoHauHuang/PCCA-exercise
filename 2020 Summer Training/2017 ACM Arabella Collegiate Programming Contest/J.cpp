#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
const double pi = acos(-1);
 
double a, l, ans;
 
double calRec(double r, double the) {
	return l * l * sin(the * (2 * pi) / 360) / 2;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		
		cin >> l >> a;
		
		if (a < eps) ans = l * l * pi;
		else if (fabs(a - (double) 180.0) < eps) {
			ans = l * l * pi / 2;
		}
		else {
			ans = l * l * pi * a / 360;
			ans = ans - calRec(l, a);
		}
		cout << fixed << setprecision(6) << ans << '\n';
	}
	return 0;
}

