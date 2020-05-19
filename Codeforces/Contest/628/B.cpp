#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, n;
	cin >> t;
	while(t--){
		cin >> n;
		long long a, ans = 0;
		map<long long, int> vis;
		
		for(int i = 0 ; i < n ; i++){
			cin >> a;
			if(!vis[a]){
				ans++;
				vis[a] = 1;
			}
		}
		
		cout << ans << endl;
		
	}


	return 0;
}

