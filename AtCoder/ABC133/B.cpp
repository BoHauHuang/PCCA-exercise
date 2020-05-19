#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, D, ans = 0;
	cin >> N >> D;
	double x[N][D];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < D ; j++){
			cin >> x[i][j];
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = i+1 ; j < N ; j++){
			int sum = 0.0;
			for(int k = 0 ; k < D ; k++){
				sum += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
			}
			if((double)sqrt(sum)-(int)sqrt(sum) == 0) ans++;
		}
	}
	
	cout << ans << endl;
	 
	return 0;
}

