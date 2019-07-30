#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, hc, hw, mc, mw, count = 1;
	cin >> T;
	while(T--){
		cin >> hc >> hw >> mc >> mw;
		
		int ans = (mc - hc) - (mw > hw);
		ans *= 60;
		ans += (mw>hw)*60+(mw-hw);
		
		cout << "Case " << count++ << ": " << ans << endl;
	}
	
	return 0;
}
