#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x, m;
	string s, cmd;
	cin >> n >> x >> s >> m >> cmd;
	string ans;
	int pos = x-1;
	
	ans += s[pos];
	for(int i = 0 ; i < cmd.size() ; i++){
		if(cmd[i] == 'R') ans = ans + s[++pos];
		else ans = ans + s[--pos];
	}
	cout << ans << endl; 
	return 0;
}

