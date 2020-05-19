#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int ans = 1;
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] <= 'Z' && s[i] >= 'A') ans++;
		}
		if(ans <= 7) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

