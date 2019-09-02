#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int dp[2][310][2], now = 0, ans = 0;

void init(){
	memset(dp, 0, sizeof(dp));
	// case: len = 1, continuous one 0 has one, continuous one 1 has one
	dp[now][1][0] = 1;
	dp[now][1][1] = 1;
}

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	init();
	for(int i = 2 ; i <= n ; i++){
		memset(dp[!now], 0, sizeof(dp[!now]));
		for(int j = 1 ; j <= ((i > a)? a : i) ; j++){
			if(dp[now][j][0]){
				if(j+1 <= a){
					// add one 0 behind string
					dp[!now][j+1][0] += dp[now][j][0];
					dp[!now][j+1][0] %= MOD;
				}
				
				// add one 1 behind string
				dp[!now][1][1] += dp[now][j][0];
				dp[!now][1][1] %= MOD;
			}
		}
		for(int j = 1 ; j <= ((i > b)? b : i) ; j++){
			if(dp[now][j][1]){
				// add one 0 behind string
				dp[!now][1][0] += dp[now][j][1];
				dp[!now][1][0] %= MOD;
				if(j+1 <= b){
					// add one 1 behind string
					dp[!now][j+1][1] += dp[now][j][1];
					dp[!now][j+1][1] %= MOD;
				}
				
			}
		}
		now = !now;
	}
	
	for(int i = 0 ; i < 2 ; i++)
		for(int j = 1 ; j <= ((i)? b : a) ; j++)
			ans = (ans+dp[now][j][i])%MOD;
	
	cout << ans << endl;
	
	return 0;
}
