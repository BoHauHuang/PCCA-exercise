#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		int a[n];
		bool has_odd = false, all_same = true;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if(a[i]%2) has_odd = true;
			if(i != 0 && a[i] != a[i-1]) all_same = false;
		}

		if(all_same && (a[0]*n)%2) cout << "YES\n";
		else if(all_same && (a[0]*n)%2 == 0) cout << "NO\n";
		else if(!has_odd && !all_same) cout << "NO\n";
		else if(has_odd && !all_same){
			bool all_odd = true;
			for(int i = 0 ; i < n ; i++)
				if(a[i]%2 == 0) all_odd = false;
			if(!all_odd || (all_odd && n%2)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}

