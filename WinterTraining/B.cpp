#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	char ans[n][n];
	ans[0][0] = 'W';
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(!j) ans[i][j] = (ans[i-1][j] == 'W')? 'B' : 'W';
			else ans[i][j] = (ans[i][j-1] == 'W')? 'B' : 'W';
			cout << ans[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
