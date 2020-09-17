#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(n == 1) cout << "0\n";
		else if(n == 2) cout << m << '\n';
		else cout << 2*m << '\n';	 
	}

	return 0;
}

