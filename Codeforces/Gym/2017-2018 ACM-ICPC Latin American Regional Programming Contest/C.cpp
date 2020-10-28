#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
 
int a[MAX];
int n, k, ok = 1;
vector<int> pls, mis;
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	mis.clear();
	pls.clear();
 
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[x] += 1;
	}
	int m = n / k;
 
	if (n % k == k - 1) m += 1;
 
	// cout << m << endl;
 
	for (int i = 1; i <= k; i++) {
		if (a[i] == m) continue;
 
		while (a[i] > m) {
			mis.push_back(i);
			a[i] -= 1;
		}
		while (a[i] < m) {
			pls.push_back(i);
			a[i] += 1;
		}
	}
	for (int i = k + 1; i < MAX; i++) {
		while (a[i] > 0) {
			mis.push_back(i);
			a[i] -= 1;
		}
	}
 
	if (mis.size() > 1) ok = 0;
	if (pls.size() > 1) ok = 0;
 
	if (!ok) {
		cout << "*\n";
		return 0;
	}
 
	if (mis.size()) {
		cout << "-" << mis[0] << ' ';
	}
	if (pls.size()) {
		cout << "+" << pls[0] << '\n';
	}
 
	return 0;
}
