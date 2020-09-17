#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long t, n;
	cin >> t;
	while(t--){
		cin >> n;
		long long m = n>>1, ans = 0;
		
		for(int i = n ; i > 1 ; i-=2){
			ans += (4*m*i-4*m);
			m--;
		}
		
		cout << ans << '\n';
	}

	return 0;
}

