#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n;
long long int ans = 0, e = 1;

void cal_front(string a){
	e = 10;
	for(int i = a.size()-1 ; i >= 0 ; i--){
		ans = (ans + ((int)(a[i]-'0')*e % MOD))%MOD;
		e*=100;
		e%=MOD;
	}
}
void cal_back(string a){
	e = 1;
	for(int i = a.size()-1 ; i >= 0 ; i--){
		ans = (ans + ((int)(a[i]-'0')*e % MOD))%MOD;
		e*=100;
		e%=MOD;
	}
}

int main(){
	cin >> n;
	string num[n];
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];
	
	for(int i = 0 ; i < n ; i++){
		cal_front(num[i]);
		cal_back(num[i]);
	}
	
	cout << ((ans%MOD)*(n%MOD))%MOD << endl;
	
	return 0;
}
