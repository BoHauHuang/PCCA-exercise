#include<bits/stdc++.h>
using namespace std;

char other(char a, char b){
	if(a == 'a' && b == 'a') return 'b';
	if(a == 'a' && b == 'b') return 'c';
	if(a == 'a' && b == 'c') return 'b';
	
	if(a == 'b' && b == 'a') return 'c';
	if(a == 'b' && b == 'b') return 'c';
	if(a == 'b' && b == 'c') return 'a';
	
	if(a == 'c' && b == 'a') return 'b';
	if(a == 'c' && b == 'b') return 'a';
	if(a == 'c' && b == 'c') return 'a';
}

int main(){
	int t;
	cin >> t;
	string s;
	
	while(t--){
		cin >> s;
		string ans = s;
		
		bool all_unknown = true, ok = true;
		
		for(int i = 0 ; i < s.size()-1 ; i++){
			if(s[i] == s[i+1] && s[i] != '?'){
				cout << "-1" << endl;
				ok = false;
				break;
			}
		}
		if(ok){
			for(int i = 0 ; i < s.size() ; i++){
				if(s[i] != '?'){
					all_unknown = false;
					break;
				}
			}	
			
			if(all_unknown){
				for(int i = 0 ; i < s.size() ; i++)
					ans[i] = 'a'+i%3;
			}
			else{
				for(int i = 0 ; i < s.size()-1 ; i++)
					if(s[i] == '?') ans[i] = (i == 0)? ((s[i+1] == 'a')? 'b' : (s[i+1] == 'b')? 'c' : 'a') : (s[i+1] == '?')? ((ans[i-1] == 'a')? 'b' : (ans[i-1] == 'b')? 'c' : 'a') : other(ans[i+1], ans[i-1]);
				if(s[s.size()-1] == '?') ans[s.size()-1] = (ans[s.size()-2] == 'a')? 'b' : (ans[s.size()-2] == 'b')? 'c' : 'a';	
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}
