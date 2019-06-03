#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	int S[N], B[N], min = 1000000000;
	for(int i = 0 ; i < N ; i++){
		cin >> S[i] >> B[i];
	}
	
	for(int i = 1 ; i < (1<<N) ; i++){
		long long s = 1, b = 0;
		for(int j = 0 ; j < N ; j++){
			if((1<<j) & i){
				s *= S[j];
				b += B[j]; 
			}
		}
		if(min > abs(s-b)) min = abs(s-b);
	}
	cout << min << '\n';
	
	return 0;
}
