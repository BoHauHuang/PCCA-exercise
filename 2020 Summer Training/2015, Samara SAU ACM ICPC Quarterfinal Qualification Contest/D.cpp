#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 0x3f3f3f3f
#define MAX 200010
 
map<lol, int> mp;
lol sum, now;
int n;
int ans_poi, ans_ele;
 
void init() {
	mp.clear();
	ans_poi = -1;
	ans_ele = INF;
}
 
int main() {
	init();
 
	cin >> n;
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> now;
		sum += now;
 
		if (mp.find(sum) != mp.end()) {
			int now_ans_poi = mp[sum] + 1;
			int now_ans_ele = i - now_ans_poi + 1;
 
			if (now_ans_ele < ans_ele) {
				ans_ele = now_ans_ele;
				ans_poi = now_ans_poi;
			}
		}
		mp[sum] = i;
 
		if (now == 0) {
			cout << i << ' ' << 1 << '\n';
			return 0;
		}
	}
	if (ans_poi != -1)
		cout << ans_poi << ' ' << ans_ele << '\n';
	else 
		cout << -1 << '\n';
	return 0;
}
