#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	
	if(n%2){
		for(auto &x : a){
			x = (x=='0')? '1' : '0';
		}
	}
	cout << ((a==b)? "Deletion succeeded" : "Deletion failed") << endl;
	
	return 0;
} 
