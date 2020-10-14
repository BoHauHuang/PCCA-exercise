#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	long long t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		cout << ceil(min(2*(sqrt(n)-1), 2*((sqrt(1+4*n)-1)/2)-1))<< '\n';
	}
	return 0;
}

