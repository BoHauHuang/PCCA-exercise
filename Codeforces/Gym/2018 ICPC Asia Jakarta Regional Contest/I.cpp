#include<bits/stdc++.h>
using namespace std;
int N;
string s;
bool truth;
 
int main(){
	cin >> N;
	cin >> s;
	truth = (s == "LIE")? false : true;
	N--;
	while(N--){
		cin >> s;
		if(s == "LIE") truth = !truth;
	}
	
	cout << ((truth)? "TRUTH" : "LIE") << endl; 
	
	return 0;
}
