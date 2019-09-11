#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	string a, in;
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		a += in;
	}
	
	a += a;
	long long ans = 0, tmp = 0;
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] == '1') tmp++;
		else tmp = 0;
		
		if(ans < tmp) ans = tmp;
	}
	
	cout << ans << endl;
	
	return 0;
}
