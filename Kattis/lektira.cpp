#include<bits/stdc++.h>
using namespace std;

int main(){
	string input;
	cin >> input;
	
	reverse(input.begin(), input.end());
	
	int last = input.size()-1;
	string s = "";
	string ss = "";
	string ans = "";
	s += input[last];
	ss += input[last];
	
	while(last > 2){
		last--;
		ss = input[last] + ss;
		if(ss < s) s = ss;
	}
	
	ans += s;
	input.erase(input.end()-s.size(), input.end());
	last = input.size()-1;
	s = "";
	ss = "";
	s += input[last];
	ss += input[last];
	
	while(last > 1){
		last--;
		ss = input[last] + ss;
		if(ss < s) s = ss;
	}
	
	ans += s;
	input.erase(input.end()-s.size(), input.end());
	
	ans += input;
	cout << ans << endl;
} 
