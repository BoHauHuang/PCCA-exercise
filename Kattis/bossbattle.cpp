#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, ans = 1;
	cin >> n;
	n -= 3;
	if(n <= 0) cout << ans << '\n';
	else cout << ans+n << '\n';
	return 0;
}
