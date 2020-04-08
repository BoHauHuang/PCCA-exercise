#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, n, x;
	cin >> t;
	
	while(t--){
		cin >> n >> x;
		long long a[n], vis[1010];
		memset(vis, 0, sizeof(vis));
		
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			vis[a[i]] = 1;
		}
		long long now = 1;
		while(x){
			if(vis[now] == 0){
				vis[now] = 1;
				x--;
				if(x > 0) now++;
			}
			else now++;
		}
		while(vis[now]){
			now++;
		}
		cout << now-1 << endl;
	}
	

	return 0;
}

