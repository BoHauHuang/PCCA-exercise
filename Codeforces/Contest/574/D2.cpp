#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n;
long long int ans = 0, e;
map<int, int> len;

long long int cal_front(string a, int b){
	long long int tmp = 0;
	e = 10;
	for(int i = a.size()-1 ; i >= 0 ; i--){
		tmp = (tmp + ((int)(a[i]-'0')*e % MOD))%MOD;
		b--;
		if(b > 0) e*=100;
		else e *= 10;
		e%=MOD;
	}
	return tmp;
}
long long int cal_back(string a, int b){
	long long int tmp = 0;
	e = 1;
	for(int i = a.size()-1 ; i >= 0 ; i--){
		tmp = (tmp + ((int)(a[i]-'0')*e % MOD))%MOD;
		b--;
		if(b >= 0) e*=100;
		else e *= 10;
		e%=MOD;
	}
	return tmp;
}

int main(){
	cin >> n;
	string num[n];
	for(int i = 0 ; i < n ; i++){
		cin >> num[i];
		len[num[i].size()]++;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(auto x : len){
			ans = ((ans%MOD)+((cal_front(num[i], x.first)%MOD)*(x.second%MOD))%MOD)%MOD;
			ans = ((ans%MOD)+((cal_back(num[i], x.first)%MOD)*(x.second%MOD))%MOD)%MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
