#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int left;
	for(int i = 0 ; i <= n/a ; i++){
		left = n - a*i;
		if(!(left%b)){
			cout << "YES" << endl << i << " " << left/b << endl;
			return 0;
		}
		
	}
	cout << "NO" << endl;
	
	return 0;
}
