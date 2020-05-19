#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n], ans = 0;
		long long sum = 0;
		
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		
		for(int i = 0 ; i < n ; i++){
			int l = 0, r = 0;
			sum = a[l];
			
			for( ; l < n && r < n ; ){
				if(r==l){
					r++;
					if(r<n) sum += a[r];
				}
				
				if(sum < a[i]){
					r++;
					if(r<n) sum += a[r];
				}
				else if(sum > a[i]){
					sum -= a[l];
					l++;
				}
				
				if(sum == a[i] && r!=l && r < n && l < n){
					ans++;
					break;
				}
				else if(sum == a[i]){
					r++;
					if(r<n) sum += a[r];
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}

