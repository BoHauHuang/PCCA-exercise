#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, in, num[2050];
		cin >> n;
		memset(num, 0, sizeof(num));
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			if(in <= 2048) num[in]++;
		}
		int carry = 0;
		for(int i = 1 ; i < 2048 ; i*=2){
			num[i] += carry;
			carry = num[i]/2;
			num[i]%=2;
		}
		num[2048] += carry;
		
		if(num[2048]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	return 0;
}
