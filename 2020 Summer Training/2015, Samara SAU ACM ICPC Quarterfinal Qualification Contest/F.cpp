#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
 
int n, m;
 
void init() {
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	cin >> n >> m;
 
	int t = max(n, m);
	int a[n + 2][m + 2], d[n + 2][m + 2], r[n + 2][m + 2], ans_r[t + 2], ans_d[t + 2], ans[t + 2];
	
	memset(a, 0, sizeof(a));
	memset(d, 0, sizeof(d));
	memset(r, 0, sizeof(r));
	memset(ans, 0, sizeof(ans));
	memset(ans_r, 0, sizeof(ans_r));
	memset(ans_d, 0, sizeof(ans_d));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
 
			a[i][j] = (c == '+' ? 0 : 1);
			d[i][j] = a[i][j];
			r[i][j] = a[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (!a[i][j]) continue;
			
			r[i][j] += r[i][j + 1];
			d[i][j] += d[i + 1][j];
		}
	}
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; ) {
			if (r[i][j] != 0) {
				ans_r[r[i][j]]++;
 
				j += r[i][j];
			} else
				j += 1;
		}
	}
 
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; ) {
			if (d[j][i] != 0) {
				ans_d[d[j][i]]++;
 
				j += d[j][i];
			} else
				j += 1;
		}
	}
 
	int sum_r = 0, sum_d = 0;
	int num_r = 0, num_d = 0;
	for (int i = t; i >= 1; i--) {
		ans[i] += sum_r + ans_r[i];
		ans[i] += sum_d + ans_d[i];
 
		sum_r = sum_r + num_r + ans_r[i] * 2;
		sum_d = sum_d + num_d + ans_d[i] * 2;
 
		num_r = num_r + ans_r[i];
		num_d = num_d + ans_d[i];
	}
	// for (int i = 1; i <= t; i++) cout << i << ": " << ans_d[i] << ", " << ans_r[i] << endl;
 
	// for (int i = 1; i <= t; i++) {
	// 	for (int j = i; j <= t; j++) {
	// 		ans[i] += ans_r[j] * (j - i + 1);
	// 		ans[i] += ans_d[j] * (j - i + 1);
	// 	}
	// }
	ans[1] /= 2;
 
	for (int i = 1; i <= t; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
