#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long a[n], pre[n], m = 1e16;
	
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		if(i == 0) pre[i] = a[i];
		else pre[i] = pre[i-1]+a[i];
	}
	for(int i = 0 ; i < n ; i++)
		m = min(pre[i], m);
	if(m >= 0) cout << "0\n";
	else cout << abs(m) << '\n';
	return 0;
}

