#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int bound = s.length();
	int num_Q = 0;
	
	for(int i = s.length()-1 ; i >= 0 ; i--){
		if(s[i] == 'Q'){
			bound = i;
			break;
		}
	}
	for(int i = bound ; i >= 0 ; i--)
		if(s[i] == 'Q') num_Q++;
		
	if(bound == s.length() || num_Q < 2) cout << "0" << endl;
	else{
		int total = 0;
		for(int i = 0 ; i <= bound ; i++){
			if(s[i] == 'Q'){
				for(int j = i+1 ; j <= bound ; j++){
					if(s[j] == 'Q'){
						for(int k = i+1 ; k < j ; k++){
							if(s[k] == 'A') total++;
						}
					}
				}
			}
		}
		cout << total << endl; 
	} 
	
	return 0;
} 
