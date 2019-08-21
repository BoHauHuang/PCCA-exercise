#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n, k;
	string s;
	cin >> q;
	while(q--){
		cin >> n >> k >> s;
		string rgb = "RGB";
		
		int ans = k, dp[n+1], color;
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0 ; i < 3 ; i++){
			color = i;
			for(int j = 1 ; j <= n ; j++){
				dp[j] = dp[j-1] + (s[j-1] != rgb[color]);
				
				color = (color+1)%3;
			}
			
			for(int j = k ; j <= n ; j++)
				if(ans > dp[j]-dp[j-k]) ans = dp[j]-dp[j-k];
		}
		cout << ans << endl;
	}
	
	return 0;
}
