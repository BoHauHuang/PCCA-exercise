#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T, x, y;
	cin >> T;
	while(T--){
		cin >> x >> y;
		cout << max(x*x, max(y*y, x*y)) << '\n';
	}
	return 0;
}

