#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int t, L, v, l, r;
	cin >> t;
	while(t--){
		cin >> L >> v >> l >> r;
		long long int dis = (r/v)-(l/v);
		cout << (L/v)-dis-(l%v == 0) << endl;
	}
	return 0;
}
