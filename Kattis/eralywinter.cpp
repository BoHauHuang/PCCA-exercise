#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, dm;
	cin >> n >> dm;
	int d[n];
	for(int i = 0 ; i < n ; i++)
		cin >> d[i];
	
	for(int i = 0 ; i < n ; i++){
		if(d[i] <= dm){
			cout << "It hadn't snowed this early in " << i << " years!" << endl;
			return 0;
		}
	}
	cout << "It had never snowed this early!" << endl;
	
	return 0;
}
