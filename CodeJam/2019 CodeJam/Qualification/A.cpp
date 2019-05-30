#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, count = 1;
	cin >> T;
	string origin;
	while(T--){
		cin >> origin;
		vector<int> copy;
		
		for(int i = origin.size()-1 ; i >= 0 ; i--){
			if(origin[i] == '4'){
				origin[i] = '2';
				copy.push_back(2);
			}
			else copy.push_back(0);
		}
		
		cout << "Case #" << count++ << ": " << origin << " ";
		bool zeros = true;
		for(int i = copy.size()-1 ; i >= 0 ; i--){
			if(zeros && copy[i] != 0) zeros = false;
			if(!zeros) cout << copy[i];
		}
		cout << endl;
	}
	
	
	return 0;
}
