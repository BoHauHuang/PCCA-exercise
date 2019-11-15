#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	
	reverse(s.begin(), s.end());
	
	int ans = 0;
	
	for(int i = 0 ; i < x ; i++)
		ans += ((i == y && s[i] != '1') || (i != y && s[i] != '0'));
	
	cout << ans << endl;	
	
	return 0;
} 
