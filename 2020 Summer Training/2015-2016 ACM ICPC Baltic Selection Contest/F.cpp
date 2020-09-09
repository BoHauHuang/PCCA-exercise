#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	double l, r;
	cin >> n;
	while(n--){
		cin >> l >> r;
		cout << fixed << setprecision(10) << ((1.0/l)-(1.0/(r+1))) << '\n';
	}
	return 0;
}

