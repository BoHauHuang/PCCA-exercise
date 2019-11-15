#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int q, n;
	cin >> q;
	
	while(q--){
		cin >> n;
		long long int ans = 0;
		bool valid = false;
		
		if(!(n%2) || !(n%3) || !(n%5)) valid = true;
		ans += valid;
		
		while(valid){
			if(!(n%2)) n = n/2;
			else if(!(n%3)) n = 2*n/3;
			else n = 4*n/5;
			
			if(!(n%2) || !(n%3) || !(n%5)) valid = true;
			else valid = false;
			
			ans += valid;
		}
		if(n == 1) cout << ans << endl;
		else cout << "-1" << endl;
	}
	return 0;
} 
