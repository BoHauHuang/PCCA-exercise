#include<bits/stdc++.h>
using namespace std;

int main(){
	int L, x, p, ans = 0;
	cin >> L >> x;
	
	while(x--){
		string s;
		cin >> s >> p;
		if(s == "enter"){
			if(L-p < 0) ans++;
			else L -= p;
		}
		if(s == "leave") L += p;
	}
	cout << ans << endl;
	return 0;
}
