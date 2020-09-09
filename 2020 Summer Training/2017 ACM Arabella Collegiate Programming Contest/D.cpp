#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, in;
	cin >> t;
	while(t--){
		cin >> n;
		bool ok = true, is_odd = false;
		cin >> in;
		
		if(in%2) is_odd = true;
		
		for(int i = 1 ; i < n ; i++){
			cin >> in;
			if(!(in%2) && is_odd) ok = false;
			if(in%2 && !is_odd) ok = false;
		}
		
		if(ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

