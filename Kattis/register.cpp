#include<bits/stdc++.h>
using namespace std;

int main(){
	int v[8], ans = 0, max[8] = {1,2,4,6,10,12,16,18}, p[8] = {2,3,5,7,11,13,17,19};
	
	for(int i = 0 ; i < 8 ; i++){
		cin >> v[i];
		if(v[i] != max[i]){
			int tmp = 1;
			for(int j = i-1 ; j >= 0 ; j--){
				tmp *= p[j];
			}
			tmp *= max[i]-v[i];
			ans += tmp;
		}
	}
	cout << ans << '\n';
	return 0;
} 
