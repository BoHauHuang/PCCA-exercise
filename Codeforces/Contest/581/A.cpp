#include<bits/stdc++.h>
using namespace std;
string s;
int one = 0;

int main(){
	cin >> s;

	for(int i = s.size()-1 ; i > 0 ; i--)
		one += (s[i] == '1');
		
	cout << (s.size()/2 + (s.size()%2 && one)) << endl;
	
	return 0;
}
