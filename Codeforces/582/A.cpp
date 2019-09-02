#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n], odd = 0, even = 0, ans = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i];
		odd += (x[i]%2);
		even += (x[i]%2 == 0);
	}
	if(odd >= even) cout << even << endl;
	else cout << odd << endl;

	return 0;
}
