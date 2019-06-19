#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 1){
		cout << "1" << endl;
		return 0;
	}
	
	int a[n+1];
	long long int odd[n+1], even[n+1];
	memset(odd,0,sizeof(odd));
	memset(even,0,sizeof(even));
	
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		
		odd[i] = odd[i-1] + a[i]*(i%2 != 0);
		even[i] = even[i-1] + a[i]*(i%2 == 0);
	}
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int o = 0, e = 0;
		o = odd[i-1] + (even[n]-even[i]);
		e = even[i-1] + (odd[n]-odd[i]);
		
		if(o == e) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
} 
