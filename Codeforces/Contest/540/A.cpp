#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long int  n, a, b;
		cin >> n >> a >> b;
		if(a*2 <= b) cout << n*a << endl;
		else cout << (long long int)(n-(n/2)*2)*a+(long long int)(n/2)*b << endl;
	}
	
	return 0;
} 
