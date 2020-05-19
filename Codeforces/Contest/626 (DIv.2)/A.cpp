#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		int a[n], ans, odd1 = -1, odd2 = -1;
		bool all_odd = true;
		
		
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if(a[i]%2 == 0){
				all_odd = false;
				ans = i+1;	
			}
			else{
				if(odd1 == -1) odd1 = i+1;
				else{
					if(odd2 == -1) odd2 = i+1;
				}
			}
		}
		
		if(!all_odd) cout << "1" << endl << ans << endl;
		else{
			if(n == 1) cout << "-1" << endl;
			else cout << "2" << endl << odd1 << " " << odd2 << endl;
		}
	}
	
	return 0;
}

