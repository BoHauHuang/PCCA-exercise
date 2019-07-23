#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n;
	vector<int> a(n, 0), prefix(n, 0);
	
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		if(!i) prefix[0] = a[0];
		else prefix[i] = prefix[i-1]+a[i];
	}
		
	cin >> m;
	int q;
	for(int i = 0 ; i < m ; i++){
		cin >> q;
		cout << lower_bound(prefix.begin(), prefix.end(), q)-prefix.begin()+1 << endl;
	}

	return 0;
}
