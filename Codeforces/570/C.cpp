#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int q, k, n, a, b;
	cin >> q;
	
	while(q--){
		cin >> k >> n >> a >> b;
		k--;
		if(n*b > k) cout << "-1" << endl;
		else cout << ((n < (k-b*n)/(a-b))? n : (k-b*n)/(a-b)) << endl;
	}
	
	return 0;
}
