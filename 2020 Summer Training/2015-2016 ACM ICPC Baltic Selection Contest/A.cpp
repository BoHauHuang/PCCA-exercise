#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string a, b;
	cin >> a >> b;
 
	int n = (int) a.length(), ans = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i] - '0';
		int y = b[i] - '0';
 
		ans *= 10;
		ans += abs(x - y);
	}
	cout << ans << '\n';
	return 0;
}
