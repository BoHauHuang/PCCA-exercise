#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	long long a, b, k;
	
	while(t--){
		cin >> a >> b >> k;
		if(!(k%2)) cout << (a-b)*(k/2) << endl;
		else cout << (a-b)*(k/2)+a << endl;
	}
	
	return 0;
}
