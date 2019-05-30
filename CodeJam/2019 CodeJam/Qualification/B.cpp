#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, count = 1, dim;
	cin >> T;
	string in;
	
	while(T--){
		cin >> dim >> in;
		vector<char> out;
		for(int i = 0 ; i < in.size() ; i++){
			if(in[i] == 'E') out.push_back('S');
			else out.push_back('E');
		}
		
		cout << "Case #" << count++ << ": ";
		for(int i = 0 ; i < out.size() ; i++)
			cout << out[i];
		cout << endl;
 	}
	
	return 0;
}
