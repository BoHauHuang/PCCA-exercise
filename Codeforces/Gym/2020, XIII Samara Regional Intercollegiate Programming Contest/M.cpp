#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, sum = 0, t, d;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> t >> d;
		if(i == 0) sum = t+d;
		else{
			if(sum >= t) sum += d;
			else sum = t+d;
		}
	}
	cout << sum << '\n';
	return 0;
}

