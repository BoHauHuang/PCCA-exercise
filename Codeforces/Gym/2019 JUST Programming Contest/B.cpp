#include<bits/stdc++.h>
using namespace std;


int b[100005];
int v[100005];
void update(int x,int v) {
	while(x <= 100000) {
		b[x] = max(b[x],v);
		x += x & (-x);
	}
}
int sum(int x) {
	int ret = 0;
	while(x) {
		ret = max(ret,b[x]);
		x -= x & (-x);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	while(t--) {
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		int n, m, q;
		cin >> n >> m >> q;
		for(int i = 0 ; i < n ;i++) {
			int x, y;
			cin >> x >> y;
			for (int j = x ; j <= y ; j++) {
				v[j] = 1;	
			}
		}
		for (int i = 1 ; i <= m ; i++) {
			v[i] ^= 1;
		}
		for (int i = 2 ; i <= m ; i++) {
			if (!v[i]) {
				continue;
			}
			else {
				v[i] = v[i-1] + 1;
			}
		}		
		for (int i = 1 ; i <= m ; i++) {
			update(m+1-i,v[i]);
		}
		while(q--) {
			int tar;
			cin >> tar;
			if (sum(100000) < tar){
				cout << "-1 -1\n";
			}
			else {
				int l = 0,r = 100000;
				while(r - l > 1) {
					int mid = (l + r) >> 1;
					if (sum(mid) >= tar) {
						r = mid;
					}
					else {
						l = mid;
					}
				}
				cout << m  + 1 - r - tar + 1<<' '<< m + 1 - r<<'\n';
			}
		}
	}
	return 0;
}

