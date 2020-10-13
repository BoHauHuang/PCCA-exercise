/*input
10
-5 1 2 -2 -1 1 -5 5 -10 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MOD 1000000007
#define MAX 1000010

lol ans_min, ans_max;
int n;
vector<lol> pos, neg; 

void init() {
	pos.clear();
	neg.clear();
	ans_max = ans_min = 0;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		lol x; cin >> x;
		if (x < 0) neg.push_back(x);
		else
			pos.push_back(x);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	if (pos.size() == 0) { // all negative

		for (int i = 1; i < n; i++) {
			lol now = neg[0] * neg[i] % MOD;
			ans_max = ans_max + now;
			ans_max = (ans_max % MOD) + MOD % MOD;
		}

		for (int i = 0; i < n - 1; i++) {
			lol now = neg[i] * neg[n - 1] % MOD;
			ans_min = ans_min + now;
			ans_min = (ans_min % MOD) + MOD % MOD;
			
		}
		cout << ans_min << ' ' << ans_max << '\n';
		return 0;
	}
	if (neg.size() == 0) { // all postive

		for (int i = 1; i < n; i++) {
			lol now = pos[0] * pos[i] % MOD;
			ans_min = ans_min + now;
			ans_min = (ans_min % MOD) + MOD % MOD;
		}

		for (int i = 0; i < n - 1; i++) {
			lol now = pos[i] * pos[n - 1] % MOD;
			
			ans_max = ans_max + now;
			ans_max = (ans_max % MOD) + MOD % MOD;
		}

		cout << ans_min << ' ' << ans_max << '\n';
		return 0;
	}
	// some neg, som pos

	int m = (int) pos.size();
	int r = (int) neg.size();

	for (int i = 0; i < m - 1; i ++) {
		lol now = pos[i] * pos[m - 1] % MOD;
			
		ans_max = ans_max + now;
		ans_max = (ans_max % MOD) + MOD % MOD;
	}
	for (int i = 1; i < r; i++) {
		lol now = neg[0] * neg[i] % MOD;
		
		ans_max = ans_max + now;
		ans_max = (ans_max % MOD) + MOD % MOD;
	}
	ans_max = ans_max + (pos[0] * neg[r - 1] % MOD);

	for (int i = 0; i < m - 1; i ++) {
		lol now = pos[i] * neg[0];

		ans_min = ans_min + now;
		ans_min = (ans_min % MOD) + MOD % MOD;
	}
	for (int i = 1; i < r; i++) {
		lol now = neg[i] * pos[m - 1];

		ans_min = ans_min + now;
		ans_min = (ans_min % MOD) + MOD % MOD;
	}
	ans_min = ans_min + (pos[m - 1] * neg[0] % MOD);

	ans_min = (ans_min + MOD) % MOD;
	ans_max = (ans_max + MOD) % MOD;

	ans_min = (ans_min + MOD) % MOD;
	ans_max = (ans_max + MOD) % MOD;

	cout << ans_min << ' ' << ans_max << '\n';
	return 0;
}
/*

10
-5 -10 -7 -7 -3 -1 -7 -5 -8 -6

10 
10 8 9 3 8 8 0 5 3 10

10
0 0 0 0 0 0 0 0 0 0 

10
-5 1 2 -2 -1 1 -5 5 -10 6

*/
