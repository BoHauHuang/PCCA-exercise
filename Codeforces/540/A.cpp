#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	long long int n, a, b;
	while(q--){
		cin >> n >> a >> b;
		long long int cost = 0;
		if(2*a > b){
			cost += b*(n/2);
			n = n-2*floor(n/2);
			cost += a*n;
		}
		else if(2*a < b){
			cost += a*n;
			n = 0;
		}
		else{
			cost += a*n;
			n = 0;
		}
		cout << cost << endl;
	}
	return 0;
}
