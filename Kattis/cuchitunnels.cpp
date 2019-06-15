#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int D[N], total = 0;
	
	for(int i = 0 ; i < N ; i++){
		cin >> D[i];
		if(i) D[i] -= 1; // not root
		total += D[i];
	}
	
	// available edge 
	long long int available = 0;
	for(int i = N-1 ; i >= 0 ; i--){
		if(D[i] > available){
			cout << "NO" << endl;
			return 0;
		}
		available-=D[i];
		available++;
	}
	if(total == N-1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
} 
