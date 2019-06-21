#include<bits/stdc++.h>
using namespace std;

int main(){
	int v[8], max[8] = {1, 2, 4, 6, 10, 12, 16, 18}, ans = 0;
	for(int i = 0 ; i < 8 ; i++){
		cin >> v[i];
		if(v[i] < max[i]){
			int tmp = 1;
			for(int j = i-1 ; j >= 0 ; j--)
				tmp *= (max[j]+1);
				
			tmp *= (max[i]-v[i]);
			ans += tmp;
		}
	}
		
	cout << ans << endl;
	
	return 0;
}
