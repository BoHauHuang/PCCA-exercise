#include<bits/stdc++.h>
using namespace std;
int cnt[200000], n;

int main(){
	cin >> n;
	int a[n];
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	
	sort(a, a+n);
	
	long long ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i]-1 > 0 && cnt[a[i]-1] == 0){
			cnt[a[i]-1]++;
			ans++;
		}
		else if(cnt[a[i]] == 0){
			cnt[a[i]]++;
			ans++;
		}
		else if(cnt[a[i]+1] == 0){
			cnt[a[i]+1]++;
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
