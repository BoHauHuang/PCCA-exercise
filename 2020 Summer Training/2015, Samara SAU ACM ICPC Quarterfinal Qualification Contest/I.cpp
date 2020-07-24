#include<bits/stdc++.h>
#define INF 1e16
using namespace std;
 
int main(){
	long long n, d, c;
	cin >> n >> d >> c;
	long long t[n+1], ans[n+1];
	
	memset(t, 0 , sizeof(t));
	memset(ans, 0 , sizeof(ans));
	
	for(int i = 1 ; i <= n ; i++){
		cin >> t[i];
		ans[i] = INF;
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			long long delay = 0;
			for(int k = j ; k < i ; k++)
				delay += (t[i]-t[k]);
			ans[i] = min(ans[i], ans[j-1]+d+delay*c);
		}
	}
 
	cout << ans[n] << endl;
	
	return 0;
}

