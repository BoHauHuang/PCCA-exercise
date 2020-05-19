#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, a, b, c, n;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> n;
		
		long long m = max(a, max(b, c));
		long long need = 3*m-a-b-c;
		if((need > n) || (need < n && (n-need)%3 != 0)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}

