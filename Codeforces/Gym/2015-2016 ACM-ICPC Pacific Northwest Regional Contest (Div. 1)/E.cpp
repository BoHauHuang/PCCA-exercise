#include<bits/stdc++.h>
using namespace std;

int main(){
	long long x;
	cin >> x;
	long long a[x];
	for(int i = 0 ; i < x ; i++)
		cin >> a[i];
	sort(a, a+x);
	long long s[x/2], ans = a[0]+a[x-1];
	for(int i = 0 ; i < x ; i+=2){
		ans = min(a[i]+a[x-1-i], ans);
	}
	cout << ans << '\n';
	return 0;
}