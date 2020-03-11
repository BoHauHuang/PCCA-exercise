#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool is_A = (s[0] == 'A');
	
	
	for(int i = 0 ; i < s.size() ; i++){
		if(is_A && s[i] != 'A'){
			cout << "Yes" << endl;
			return 0;
		}
		if(!is_A && s[i] != 'B'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	return 0;
}

