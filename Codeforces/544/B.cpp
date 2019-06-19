#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, in;
	cin >> n >> k;
	
	int d[105];
	memset(d, 0, sizeof(d));
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		d[(in%k)]++;
	}
	
	int ans = 0;
	int mid = (k%2)? (k+1)/2 : k/2;
	
	for(int i = 1 ; i < mid ; i++)
		if(d[k-i] && d[i]) ans = (d[i] > d[k-i])? ans+d[k-i]*2 : ans+d[i]*2;
	
	
	ans += ((d[0]/2)*2);
	if(mid*2 == k) ans += ((d[mid]/2)*2);
	
	cout << ans << endl;
	
	return 0;
} 
