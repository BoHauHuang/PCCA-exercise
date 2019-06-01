#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, N;
	cin >> T;
	int last[11];
	memset(last, 0, sizeof(last));
	last[1] = 1;
	for(int i = 2 ; i <= 10 ; i++)
		last[i] = (last[i-1]*i)%10;
	
	while(T--){
		cin >> N;
		cout << last[N] << endl;
	}
	
	return 0;
}
