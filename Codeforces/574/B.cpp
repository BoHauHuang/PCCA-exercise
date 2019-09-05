#include<bits/stdc++.h>
using namespace std;
long long int n, k;

int main(){
	cin >> n >> k;	

	for(long long int i = 1 ; i <= n ; i++){
		if(i*(i+1)/2 - (n-i) == k){
			cout << n-i << endl;
			return 0;
		}
	}	
}
