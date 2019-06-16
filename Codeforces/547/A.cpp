#include<bits/stdc++.h>
#define INVALID (n < m && n*2 > m) || origin != result || origin*n != m
using namespace std;

int main(){
	long long int n, m;
	cin >> n >> m;
	long long int mul = m/n;
	long long int result = 1, origin = mul, ans = 0;
	
	while(mul > 1){
		if(mul >= 3 && !(mul%3)){
			mul/=3;
			result*=3;
			ans++;
		}
		if(mul >= 2 && !(mul%2)){
			mul/=2;
			result*=2;
			ans++;
		}
		if(mul%2 && mul%3) break;
	}
	
	if(INVALID) cout << "-1" << endl;
	else cout << ans << endl;
	
	return 0;
}
