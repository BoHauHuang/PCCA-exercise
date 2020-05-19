#include<bits/stdc++.h>
using namespace std;

int main(){
	long long X, ans = 0;
	cin >> X;
	
	ans += (X/500)*1000;
	X%=500;
	ans += (X/5)*5;
	
	cout << ans << endl;

	return 0;
}

