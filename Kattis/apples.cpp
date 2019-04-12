#include<bits/stdc++.h>
using namespace std;

int main(){
	int R, C;
	cin >> R >> C;
	char map[R][C];
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> map[i][j];
		}
	}
	char ans[R][C];
	
	for(int j = 0 ; j < C ; j++){
		int cnt = 0;
		for(int i = 0 ; i < R ; i++)
			if(map[i][j] == '#') cnt++;
		int space[cnt+1], apple = 0, spcnt = 0;
		
		memset(space, 0, sizeof(space));
		for(int i = R-1 ; i >= 0 ; i--){
			if(map[i][j] == 'a') apple++;
			if(map[i][j] == '#'){
				space[spcnt++] = apple;
				apple = 0;
			}
			if(i == 0) space[spcnt++] = apple;
		}
		spcnt = 0;
		
		for(int i = R-1 ; i >= 0 ; i--){
			if((map[i][j] == '.' || map[i][j] == 'a') && space[spcnt] > 0){
				ans[i][j] = 'a';
				space[spcnt]--;
			}
			else if(space[spcnt] == 0 && map[i][j] != '#') ans[i][j] = '.';
			else if(map[i][j] == '#'){
				ans[i][j] = '#';
				spcnt++;
			}
		}
	}
	
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cout << ans[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
