#include<bits/stdc++.h>
using namespace std;

int ham(int x){
	int h = 0;
	while(x){
		h += (x%2);
		x >>= 1;
	}
	return h;
}

int main(){
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		int A[N], ans = 0;
		for(int i = 0 ; i < N ; i++)
			cin >> A[i];
		
		for(int i = 0 ; i < N ; i++){
			for(int j = i+1 ; j < N ; j++){
				ans = max(ans, ham(A[i]^A[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}

