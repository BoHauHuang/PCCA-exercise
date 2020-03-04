#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		
		cin >> n >> s;
		
		pair<int, int> a[n], origin = make_pair(0, 0);
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'L') a[i] = make_pair(-1, 0);
			else if(s[i] == 'R') a[i] = make_pair(1, 0);
			else if(s[i] == 'U') a[i] = make_pair(0, 1);
			else a[i] = make_pair(0, -1);
		}
		
		map<pair<int, int>, int> vis;
		pair<int, int> pos[n+1], ans = make_pair(-1, -1);
		int len = n+5;
		pos[0] = origin;
		
		for(int i = 1 ; i <= n ; i++){
			pos[i].first = pos[i-1].first+a[i-1].first;
			pos[i].second = pos[i-1].second+a[i-1].second;
			//cout << pos[i].first << " " << pos[i].second << endl;
			if(vis[pos[i]] != 0){
				if(len > i-vis[pos[i]]+1){
					len = i-vis[pos[i]]+1;
					ans = make_pair(vis[pos[i]]+1, i);
					
					if(len == 2) break;
				}
			}
			else if(pos[i] == origin){
				if(len > i){
					len = i;
					ans = make_pair(1, i);
					
					if(len == 2) break;
				}
			}
			
			vis[pos[i]] = i;
		}
		
		if(ans.first == -1) cout << "-1\n";
		else cout << ans.first << " " << ans.second << endl;
	}

	return 0;
}

