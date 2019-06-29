#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) return 0;
		
		cout << "f91(" << n << ") = " << ((n <= 100)? 91 : n-10) << endl;
	}
}
