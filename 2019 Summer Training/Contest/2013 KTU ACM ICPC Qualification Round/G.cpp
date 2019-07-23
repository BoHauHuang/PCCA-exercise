#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
long long fpow(int a){
	long long tmp = a, exp = MOD-2, res = 1;
	
	while(exp){
		if(exp%2) res = (res*tmp)%MOD;
		tmp = (tmp*tmp)%MOD;
		exp >>= 1;
	}
	
	return res;
}
 
int main(){
	int T, n, count = 1;
	cin >> T;
	while(T--){
		cin >> n;
		
		int in[n], ans = 0;
		map<int, int> vis;
		map<int, int>::iterator it;
		
		for(int i = 0 ; i < n ; i++){
			cin >> in[i];
			vis[in[i]]++;
		}
		
		
		for(it = vis.begin() ; it != vis.end() ; it++){
			long long other = fpow(it->first);
			if(other == it->first){
				int cnt = it->second/2;
				ans += cnt;
				it->second = 0;
			}
			else{
				int cnt = (vis[other] > it->second)? it->second : vis[other];
				ans += cnt;
				
				if(vis[other] > it->second) vis[other] -= cnt;
				else vis[other] = 0;
				
				it->second -= cnt;
			}
		}
		
		cout << "Case #" << count++ << ": " << ans << endl;
	}
	return 0;
}
