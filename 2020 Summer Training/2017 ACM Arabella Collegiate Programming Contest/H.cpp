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
		bool ok = true;
		
		for(int i = 0 ; i < s.size() ; i++)
			if(!valid[s[i]]) ok = false;
		
		for(int i = 0, j = s.size()-1 ; i < j ; i++, j--)
			if(s[i] != s[j]) ok = false;
		
		if(ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

