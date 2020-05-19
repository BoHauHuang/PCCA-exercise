#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int cnt = 0, ans[2] = {0};
		for(long long i = 2 ; i*i < n ; i++){
			if(n%i == 0){
				n /= i;
				ans[cnt++] = i;
			}
			if(cnt == 2) break;
		}
		if(cnt != 2) cout << "NO" << endl;
		else cout << "YES" << endl << ans[0] << " " << ans[1] << " " << n << endl;
		
	}
	
	return 0;
}

