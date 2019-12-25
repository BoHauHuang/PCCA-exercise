#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t, r, b, k;
	cin >> t;
	while(t--){
		cin >> r >> b >> k;
		int g = __gcd(r, b);		
		if(r == b){
			cout << "OBEY" << endl;
			continue;	
		}
		r/=g;
		b/=g;
		
		if(r < b) swap(r, b);
		
		r--;
		if(b*(k-1) < r) cout << "REBEL" << endl;
		else cout << "OBEY" << endl; 
	}
	
	return 0;
}
 
