#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	map<char, int> valid;
	
	cin >> t;
	
	valid['A'] = 1;
	valid['H'] = 1;
	valid['I'] = 1;
	valid['M'] = 1;
	valid['O'] = 1;
	valid['T'] = 1;
	valid['U'] = 1;
	valid['V'] = 1;
	valid['W'] = 1;
	valid['X'] = 1;
	valid['Y'] = 1;
	
	while(t--){
		cin >> s;
		queue<string> split;
		bool ok = true;
		string sp = "";
		int ans = 0;
		
		for(int i = 0 ; i < s.size() ; i++){
			if(valid[s[i]]) sp = sp+s[i];
			else{
				if(sp != "") split.push(sp);
				sp = "";
			}
		}
		if(sp != "") split.push(sp);
		
		while(!split.empty()){
			ans = (ans < 1)? 1 : ans;
			string now = split.front();
			split.pop();
			if(now.size() < 3){
				if(now.size() == 2 && now[0] == now[1]) ans = (ans < 2)? 2:ans;
				if(now.size() == 1) ans = (ans < 1)? 1:ans;
			}
			else{
				for(int mid = 1 ; mid < now.size()-1 ; mid++){
					int l = mid-1, r = mid+1;
					
					while(l >= 0 && r < now.size()){
						if(now[l] == now[r]){
							ans = (r-l+1 > ans)? r-l+1 : ans;
							l--;
							r++;
						}
						else break;
					}
				}
				
				for(int mid = 0 ; mid < now.size()-1 ; mid++){
					int l = mid, r = mid+1;
					
					while(l >= 0 && r < now.size()){
						if(now[l] == now[r]){
							ans = (r-l+1 > ans)? r-l+1 : ans;
							l--;
							r++;
						}
						else break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

