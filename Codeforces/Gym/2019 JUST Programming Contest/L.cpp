#include<bits/stdc++.h>
using namespace std;
int pre[1005][1005];
int val[1005][1005];
int n,m;
int w,h;
int tar;
void build(int x) {
	memset(pre,0,sizeof(pre));
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (val[i][j] <= x) {
				pre[i][j] = 1;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]; 
		}
	}
}
bool check() {
	for (int i = h ; i <= n ; i++) {
		for (int j = w ; j <= m ; j++) {
			int tot = pre[i][j] - pre[i-h][j] - pre[i][j-w] + pre[i-h][j-w];
			if (tot >= tar) {
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h >> w;
	tar = h * w / 2 + 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> val[i][j];
		}
	}
	int l = 0, r = n * m;
	while(r - l > 1) {
		int mid = (l + r) >> 1;
		build(mid);
		if (check()) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r << endl;
}

