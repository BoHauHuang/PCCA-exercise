#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long n, s, in, ans = 0;
	cin >> n >> s;
	
	vector<long long> coin;
	coin.push_back(1);
	
	for(long long i = 0 ; i < n ; i++){
		cin >> in;
		if(in*coin[coin.size()-1] > s) break;
		coin.push_back(in*coin[coin.size()-1]);
	}
	
	for(long long i = coin.size()-1 ; i >= 0 ; i--){
		ans += (s/coin[i]);
		s %= coin[i];
	}
	cout << ans << endl;
	
	return 0;
}
