#include<bits/stdc++.h>
using namespace std;

int main(){
	long long L, R, ans = 2020;
	cin >> L >> R;
	for(long long i = L ; i <= R ; i++){
		if(i%2019 == 0){
			cout << "0" << endl;
			return 0;
		}
	}
	for(long long i = L ; i+1 <= L+2020 && i+1 <= R ; i++){
		for(long long j = i+1 ; j <= R ; j++){
			ans = (ans < ((i%2019)*(j%2019))%2019)? ans : ((i%2019)*(j%2019))%2019;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

