#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	if(n%2){
		cout << "-1" << endl;
		return 0;
	}
	int left = 0, need = 0, ans = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '(') left++;
		else left--;
		
		if(left < 0) need++;

		if(left == 0 && need > 0){
			ans += need+1;
			need = 0;
		}
	}
	if(left != 0) cout << "-1" << endl;
	else cout << ans << endl;

	return 0;
}

