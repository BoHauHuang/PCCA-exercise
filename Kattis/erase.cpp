#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string before, after;
	cin >> N >> before >> after;
	if(N%2){
		bool success = true;
		for(int i = 0 ; i < before.size() ; i++){
			if(before[i] - after[i] == 0) success = false;
		}
		if(success) cout << "Deletion success" << endl;
		else cout << "Deletion failed" << endl;
	}
	else{
		if(before == after) cout << "Deletion success" << endl;
		else cout << "Deletion failed" << endl;
	}
	
	return 0;
}
