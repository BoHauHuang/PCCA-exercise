#include<bits/stdc++.h>
using namespace std;

int main(){
	int A, B, n = 1;
	cin >> A >> B;
	
	while(n <= 1250){
		if((8*n/100) == A && n/10 == B){
			cout << n << endl;
			return 0;
		}
		else n++;
	}
	
	cout << "-1" << endl;
	
	return 0;
}

