#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n, x;
	cin >> t;
	while(t--){
		cin >> n >> x;
		n-=2;
		if(n<=0) cout << "1\n"; 
		else cout << ceil((float)n/x)+1 << '\n';
	}
	return 0;
}

