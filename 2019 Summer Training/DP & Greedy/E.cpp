#include<bits/stdc++.h>
#define NEG_INF -9999
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> m >> n && m && n){
		long long int a[m+1][n], in;
		memset(a, 0, sizeof(a));
		
		for(int i = 1 ; i <= m ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> in;
				a[i][j] = (!in)? 1 : NEG_INF;
				a[i][j] += ((i)? a[i-1][j] : 0);
			}
		}
		
		long long int ans = 0;
		for(int i = 0 ; i < m ; i++){
			for(int j = i+1 ; j <= m ; j++){
				long long int tmp = 0;
				
				for(int k = 0 ; k < n ; k++){
					long long int subsum = a[j][k] - a[i][k];
					if(tmp > 0) tmp += subsum;
					else tmp = subsum;
					
					ans = (tmp > ans)? tmp : ans;
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
