#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, in;
	cin >> t;
	
	while(t--){
		cin >> n;
		int cnt[3], ans = 0;
		memset(cnt, 0, sizeof(cnt));
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			cnt[in%3]++;
		}
		
		ans += cnt[0];
		if(cnt[1] > cnt[2]){
			ans += cnt[2];
			cnt[1] -= cnt[2];
			ans += cnt[1]/3;
		}
		else{
			ans += cnt[1];
			cnt[2] -= cnt[1];
			ans += cnt[2]/3;
		}
		
		cout << ans << endl;
	}
	
	
	return 0;
}
