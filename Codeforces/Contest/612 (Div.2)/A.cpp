#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n, ans = 0;
		string s;
		
		cin >> n >> s;
		bool done = true;
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] == 'A' && s[i+1] == 'P') done = false;
		
		while(!done){
			vector<int> idx;
			for(int i = 0 ; i < s.size() ; i++){
				if(s[i] == 'A' && s[i+1] == 'P') idx.push_back(i+1);
			}
			
			if(idx.empty()) break;
			
			for(auto x : idx)
				s[x] = 'A';
			ans++;
			idx.clear();
		}
		cout << ans << endl;
	}
	

	return 0;
}

