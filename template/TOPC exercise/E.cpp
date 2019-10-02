#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], ans = 0;
	
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		if(a[i] == i) ans++;
	}
	bool two = false;
	for(int i = 0 ; i < n ; i++)
		if(a[a[i]] == i && a[i] != i) two = true;
	
	
	if(n >= 2 && two) ans += 2;
	else if(n >= 2 && !two && ans != n) ans++; 
	
	cout << ans << endl;
	
	return 0;
}
