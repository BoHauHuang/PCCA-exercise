#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;

		int cnt = 0;
		for(int i = 0 ; i < k; i++){
			if(i == k-1){
				while(cnt < n){
					cout << (char)('a'+i);
					cnt++;
				}
			}
			else{
				int x = n/k;
				while(x--) cout << (char)('a'+i);
				cnt += n/k;
			}
		}
		cout << endl;
		
	}
	return 0;
}
