#include<bits/stdc++.h>
#define INF 200100
using namespace std;
string s;
int q;
vector<vector<int> > idx;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> q;
	vector<int> tmp;
	for(int i = 0 ; i < 30 ; i++)
		idx.push_back(tmp);

	// index for each alpabet start
	for(int i = 0 ; i < s.size() ; i++)
		idx[s[i]-'a'].push_back(i);
			
	stack<int> record, index;
	
	
	while(q--){
		string cmd;
		char in;
		bool state = true;
		
		cin >> cmd;
		if(cmd == "push"){
			cin >> in;
			
			int last_idx = -1;
			if(!index.empty()) last_idx = index.top();
			
			auto it = upper_bound(idx[in-'a'].begin(), idx[in-'a'].end(), last_idx);
			if(it != idx[in-'a'].end()) index.push(*it);
			else{
				state = false;
				index.push(INF);
			}
			
			record.push(state);
		}
		else{
			index.pop();
			record.pop();
			if(!record.empty()) state = record.top();
		}
		if(state) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	
	return 0;
}
