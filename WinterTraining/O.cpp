#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n, in, cnt[6005];
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		cnt[in]++;
	}
	long long ans = 0;
	for(int i = 0 ; i < 6002 ; i++){
		if(cnt[i] > 1){
			ans += cnt[i]-1;
			cnt[i+1] += cnt[i]-1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
