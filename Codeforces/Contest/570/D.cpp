#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n;
	cin >> q;
	while(q--){
		cin >> n;
		int a[n];
		map<int, int> cnt;
		map<int, int> done;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		int ans = 0;
		for(auto x : cnt){
			for(int i = x.second ; i > 0 ; i--){
				if(done[i] == 0){
					ans += i;
					done[i] = 1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
