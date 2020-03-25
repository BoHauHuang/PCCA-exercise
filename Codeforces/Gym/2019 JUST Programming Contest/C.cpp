#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, n, m;
	cin >> T;
	while(T--){
		 cin >> n >> m;
		if(n%2 && m%2) cout << "12" << endl;
		else cout << "2" << endl;
	}
	
	return 0;
}

