#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s, ans;
	cin >> n >> s;
	
	char buf = '#';
	for(int i = 0 ; i < n ; i++){
		if(buf == '#') buf = s[i];
		
		if(buf != s[i]){
			ans += buf;
			ans += s[i];
			buf = '#';
		}
	}
	
	cout << s.size()-ans.size() << endl << ans << endl; 
	
	return 0;
}
