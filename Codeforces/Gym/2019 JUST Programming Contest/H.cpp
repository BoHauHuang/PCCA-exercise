#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		bool ok = true;
		int cur = s[0]-'a';
		for(int i = 1 ; i < s.size() ; i++){
			cur++;
			cur%=26;
			ok &= (cur == s[i]-'a');
		}
		cout << ((ok)? "YES" : "NO") << endl;
	}
	
	return 0;
}

