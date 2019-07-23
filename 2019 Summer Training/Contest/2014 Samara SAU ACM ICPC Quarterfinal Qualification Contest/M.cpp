#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	
	cout << a*b << endl;
	for(int i = 1 ; i <= a ; i++){
		for(int j = i*b ; j > b*(i-1) ; j--){
			cout << j << " ";
		}
	}
	cout << endl;
	
	return 0;
}
