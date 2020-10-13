#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 2000010
 
int n;
lol a[MAX];
lol ans = 0, cnt = 1;
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a , a + n, greater<int>());
 
	for (int i = 0; i < n; i++) {
		lol now = a[i];
 
		if (now > cnt) {
			ans += now - cnt;
			cnt += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
