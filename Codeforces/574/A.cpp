#include<bits/stdc++.h>
using namespace std;
int n, k, in, remain = 0, a[1010];

int main(){
	cin >> n >> k;
	memset(a, 0, sizeof(a));
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		a[in]++;
	}
	for(int i = 1 ; i <= k ; i++){
		a[i] %= 2;
		remain += a[i];
	}
	
	cout << n-(int)remain/2 << endl;

	return 0;
} 
