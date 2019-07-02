#include<bits/stdc++.h>
#define NUM 11
using namespace std;
bool origin[NUM][NUM], tmp[NUM][NUM];
int ans;

void press(int i, int j){
	ans++;
	tmp[i][j] = !tmp[i][j];
	
	if(i < 10) tmp[i+1][j] = !tmp[i+1][j];
	if(j < 10) tmp[i][j+1] = !tmp[i][j+1];
	if(i) tmp[i-1][j] = !tmp[i-1][j];
	if(j) tmp[i][j-1] = !tmp[i][j-1];
}

bool verify(){
	for(int i = 1 ; i <= 10 ; i++){
		for(int j = 1 ; j <= 10 ; j++){
			if(tmp[i][j]) return false;
		}
	}
	return true;
}

int main(){
	string s;
	while(cin >> s && s != "end"){
		char in;
		for(int i = 1 ; i <= 10 ; i++){
			for(int j = 1 ; j <= 10 ; j++){
				cin >> in;
				origin[i][j] = (in == '#')? false : true; 
			}
		}
		
		int m = 105;
		for(int i = 0 ; i < (1<<10) ; i++){
			ans = 0;
			for(int j = 1 ; j <= 10 ; j++){
				for(int k = 1 ; k <= 10 ; k++){
					tmp[j][k] = origin[j][k];
				}
			}
			
			for(int j = 0 ; j < 10 ; j++){
				if(i & (1<<j)) press(1, j+1);
			}
			
			for(int j = 1 ; j <= 9 ; j++){
				for(int k = 1 ; k <= 10 ; k++){
					if(tmp[j][k]) press(j+1, k);
				}
			}
			
			if(verify() && ans < m) m = ans; 
			
		}
		if(m > 100) m = -1;
		cout << s << " " << m << endl;
	} 
	return 0;
}
