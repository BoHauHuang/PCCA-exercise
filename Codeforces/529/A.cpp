#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	
	int len = 1;
	for(int i = 0 ; i < n ; ){
		ans += s[i];
		i+=len;
		len++;
	}
	cout << ans << endl;
	return 0;
}
