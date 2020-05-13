#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n==2 || n == 3){
			cout << "-1" << endl;
			continue; 
		}
		int ans[n], pos = 0;
		
		for(int i = ((n%2)? 1 : 2) ; i <= n && pos < n ; i+=2)
			ans[pos++] = i;
		
		if(pos < n) ans[pos++] = n-3;
		if(pos < n) ans[pos++] = n-1;
		if(pos < n){
			for(int i = n-5 ; i > 0 ; i-=2)
				ans[pos++] = i;
		}
		
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << " ";
		cout << endl; 
	}

	return 0;
}

