#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		queue<int> pos;
		int ans = 0, pre = 0;
		
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] == 'R') pos.push(i+1);
			
		if(pos.empty()){
			cout << s.size()+1 << endl;
			continue;
		}
		
		pos.push(s.size()+1);
		
		while(!pos.empty()){
			ans = (pos.front()-pre > ans)? pos.front()-pre : ans;
			pre = pos.front();
			pos.pop();
		}
		
		cout << ans << endl;
	}
	return 0;
}

