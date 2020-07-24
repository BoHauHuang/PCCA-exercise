#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		bool ok = true;
		cin >> a[0];
		int type = (a[0]%2)? 1 : 0;
		
		for(int i = 1 ; i < n ; i++){
			cin >> a[i];
			ok &= (a[i]%2 == type);
		}
		
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}

