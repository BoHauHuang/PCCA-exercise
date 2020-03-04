#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n], now, ans = 0;
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		
		now = a[n-1];
		for(int i = n-2 ; i >= 0 ; i--){
			if(now < a[i]) ans++;
			now = min(now, a[i]);
		}
		
		cout << ans << endl;
		
	}
	return 0;
}

