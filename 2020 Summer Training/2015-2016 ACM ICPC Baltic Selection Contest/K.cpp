#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	set<long long> vis;
	long long fac[25];
	long long n, a;
	fac[0] = 1;
	fac[1] = 1;
	for(int i = 2 ; i < 20 ; i++)
		fac[i] = fac[i-1]*i;
	
	vis.insert(1);
	for(int i = 2 ; i < 20 ; i++){
		for(auto x : vis){
			while((1e18)/x > fac[i]){
				vis.insert(x*fac[i]);
				x*=fac[i];
			}
		}
	}
	
	cin >> n;
	while(n--){
		cin >> a;
		cout << ((vis.count(a) != 0)? "YES\n" : "NO\n");
	}
	return 0;
}

