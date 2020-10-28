#include <bits/stdc++.h>
using namespace std;
#define MAX 25
 
struct ant {
	int x, p, dx;
 
	bool operator < (const ant& rhs) const {
		return x > rhs.x;
	}
};
 
ant a[MAX];
int n, l;
 
void init() {
	memset(a, 0, sizeof(a));
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	while (cin >> n >> l) {
		if (n + l == 0) break;
 
		init();
		for (int i = 1; i <= n; i++) {
			int x; char c; cin >> c >> x;
 
			a[i].p = i;
			a[i].x = x;
 
			if (c == 'L') a[i].dx = -1;
			if (c == 'R') a[i].dx =  1;
		}
 
		int rem = n, tim = 0, ok = 0;
		while (rem > 0) {
			tim += 1;
			for (int i = 1; i <= n; i++) {
				if (a[i].x < 1) continue;
				if (a[i].x > l) continue;
 
				a[i].x += a[i].dx;
 
				if (a[i].x == 0 || a[i].x == l) {
					rem -= 1;
 
					if (rem == 0) {
						ok = 1;
						cout << tim  << ' ' << a[i].p << '\n';
						break;
					}
				} 
			}
			if (ok) break;
			sort(a + 1, a + 1 + n);
 
			for (int i = 1; i <= n; i++) {
				if (a[i].x < 1) continue;
				if (a[i].x > l) continue;
 
				if (a[i].x == a[i + 1].x) {
					swap(a[i].p, a[i + 1].p);
					i ++;
				}
			}
		}
	}
	return 0;
}
