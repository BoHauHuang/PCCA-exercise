#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, ans = 0, k = 0;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> a >> b;
		if(a > k){
			k = a;
			if(ans < b) ans = b;
		}
	}
	
	cout << ans << endl; 
	
	return 0;
}
