#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long s, ans = 0;
		cin >> s;
		
		while(s){
			long long cashback;
			
			if(s >= 10){
				ans += (s/10)*10;
				cashback = s/10;
				s %= 10;
				s += cashback;
			}
			else{
				ans += s;
				s = 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

