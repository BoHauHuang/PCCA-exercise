#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
long long int dp[MAX][2], n, a[MAX], b[MAX];

int main(){
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
		
	dp[0][0] = a[0]; 
	dp[0][1] = b[0];
	
	for(int i = 1 ; i < n ; i++){
		dp[i][0] = (i==1)? dp[i-1][1]+a[i] : max(dp[i-1][1]+a[i], dp[i-2][1]+a[i]);
		dp[i][1] = (i==1)? dp[i-1][0]+b[i] : max(dp[i-1][0]+b[i], dp[i-2][0]+b[i]);
	}
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	
	return 0;
}
