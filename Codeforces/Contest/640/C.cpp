#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		long long g = k/(n-1);
		cout << g*(n-1)+((k%(n-1))? g : g-1)+(k-(n-1)*g) << endl;
	}

	return 0;
}
