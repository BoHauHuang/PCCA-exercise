#include<bits/stdc++.h>
using namespace std;

int main(){
	int P;
	cin >> P;
	
	int dp[101][101];
	
	for(int i = 2 ; i < 101 ; i++){
		dp[i][0] = 1;
		for(int j = 1 ; j < i-1 ; j++){
			// origin: j descents
			// remain j descents => j+1 combination => j origin descents pair + at last place = j+1
			
			// origin: j-1 descents
			// pair of descents added => other combination will change pair of descents
			// => (i+1)-(j+1) = (i-j) => (number of choices) - (choices not change number of pair)
			dp[i][j] = (dp[i-1][j]*(j+1) + dp[i-1][j-1]*(i-j))%1001113;
		}
		dp[i][i-1] = 1;
	}
	
	while(P--){
		int K, N, v;
		cin >> K >> N >> v;
		cout << K << " " << dp[N][v] << endl;
	}
	
	return 0;
}
