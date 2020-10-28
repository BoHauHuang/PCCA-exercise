#include <bits/stdc++.h>
using namespace std;
#define MAX 25
 
int a[MAX];
int n, k, s, ans;
 
void init() {
	ans = 0;
	for (int i = 1; i < MAX; i++) a[i] = i;
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
	
	while (cin >> n >> k >> s) {
		if (n + k + s == 0) break;
		ans = 0;
 
		for (int i = 0; i < (1 << n); i++) {
			int sum = 0, cnt = 0;
			for (int j = 1; j <= n; j++) if (i & (1 << (j - 1))) {
				cnt += 1;
				sum += a[j];
			}
			if (sum > s || cnt > k) continue;
			if (cnt == k && sum == s) ans += 1; 
		}
		cout << ans << '\n';
	}
	return 0;
}
