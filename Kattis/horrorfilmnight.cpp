#include<bits/stdc++.h>
using namespace std;

int main(){
	int k1, k2, in, max = 0;
	bool one[1000005], two[1000005];
	memset(one, 0, sizeof(one));
	memset(two, 0, sizeof(two));
	
	cin >> k1;
	for(int i = 0 ; i < k1 ; i++){
		cin >> in;
		one[in] = true;
		if(max < in) max = in;
	}
	cin >> k2;
	for(int i = 0 ; i < k2 ; i++){
		cin >> in;
		two[in] = true;
		if(max < in) max = in;
	}
	int cnt = 0;
	bool one_ava = true, two_ava = true;
	for(int i = 0 ; i <= max ; i++){
		if(one[i] && two[i]){
			one_ava = true;
			two_ava = true;
			cnt++;
		}
		else if(one[i] && one_ava){
			one_ava = false;
			two_ava = true;
			cnt++;
		}
		else if(two[i] && two_ava){
			one_ava = true;
			two_ava = false;
			cnt++;
		}
	}
	
	cout << cnt << endl; 
	
	return 0;
}
