#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n==1){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	
	if(n%2 == 0){
		cout << "1 " << n/2 << endl;
		cout << n-1 << " ";
		for(int i = 1 ; i <= n ; i++)
			if(i != n/2) cout << i << " ";
		cout << endl;
	}
	else{
		cout << "1 " << (n+1)/2 << endl;
		cout << n-1 << " ";
		for(int i = 1 ; i <= n ; i++)
			if(i != (n+1)/2) cout << i << " ";
		cout << endl;
	}

	return 0;
}

