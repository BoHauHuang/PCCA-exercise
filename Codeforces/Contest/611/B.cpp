#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << (n/k)*k+(((n-(n/k)*k) > k/2)? k/2 : (n-(n/k)*k)) << endl;
	}

	return 0;
}

