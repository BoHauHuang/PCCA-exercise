#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, count = 1;
	cin >> T;
	string s;
	
	while(T--){
		cin >> s;
		int mod_pos;
		
		for(int i = s.size()-1 ; i >= 0 ; i--){
			if(s[i] < s[i-1]){
				mod_pos = i-1;
				s[i-1]--;
				for(int j = mod_pos+1 ; j < s.size() ; j++)
					s[j] = '9';
			}
		}
		
		
		// output
		cout << "Case #" << count++ << ": ";
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '0' && i == 0) ;
			else cout << s[i];
		}
		cout << endl;
	}
	
	return 0;
}
