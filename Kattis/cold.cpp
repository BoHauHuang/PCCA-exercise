#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, t, cnt = 0;
	cin >> n;
	while(n--){
		cin >> t;
		if(t < 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
