#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	for(int i = 1 ; i*i <= n ; i++){
		if((int)sqrt(n-i*i)*(int)sqrt(n-i*i) == n-i*i){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
