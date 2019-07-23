#include<bits/stdc++.h>
using namespace std;

bool AB_BA(string s){
	bool yes1 = false, yes2 = false;
	if(s.size() <= 3) return false;
	
	for(int i = 0 ; i < s.size()-1 ; i++){
		if(s[i] == 'A' && s[i+1] == 'B'){
			s.replace(i,2,"XX");
			yes1 = true;
			break;
		}
	}
	if(yes1 && s.size() > 1){
		for(int i = 0 ; i < s.size()-1 ; i++){
			if(s[i] == 'B' && s[i+1] == 'A'){
				s.replace(i,2,"XX");
				yes2 = true;
				break;
			}
		}
	}
	
	return yes1&&yes2;
}

bool BA_AB(string s){
	bool yes1 = false, yes2 = false;
	if(s.size() <= 3) return false;
	
	for(int i = 0 ; i < s.size()-1 ; i++){
		if(s[i] == 'B' && s[i+1] == 'A'){
			s.replace(i,2,"XX");
			yes1 = true;
			break;
		}
	}
	if(yes1 && s.size() > 1){
		for(int i = 0 ; i < s.size()-1 ; i++){
			if(s[i] == 'A' && s[i+1] == 'B'){
				s.replace(i,2,"XX");
				yes2 = true;
				break;
			}
		}
	}
	
	return yes1&&yes2;
} 

int main(){
	string s;
	cin >> s;
	
	cout << ((AB_BA(s) || BA_AB(s))? "YES" : "NO") << endl;

	return 0;
}
