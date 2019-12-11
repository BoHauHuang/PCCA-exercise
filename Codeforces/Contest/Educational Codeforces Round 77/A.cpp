#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int c, sum;
		cin >> c >> sum;
		int a[c], cnt = 0;
		memset(a, 0, sizeof(a));
		
		while(sum--){
			a[cnt++]++;
			cnt%=c;
		}
		int ans = 0;
		for(int i = 0 ; i < c ; i++)
			ans += a[i]*a[i];
		
		cout << ans << endl;
	}
	
	return 0;
}

