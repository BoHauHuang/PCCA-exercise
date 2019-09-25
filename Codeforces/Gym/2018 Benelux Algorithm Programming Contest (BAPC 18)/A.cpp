#include<bits/stdc++.h>
using namespace std;
long long int n, X, ans = 1;
 
int main(){
	cin >> n >> X;
	long long int a[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	for(int i = 1 ; i < n ; i++)
		if(a[i]+a[i-1] <= X) ans = i+1;
	
	cout << ans << endl;
	return 0;
}
