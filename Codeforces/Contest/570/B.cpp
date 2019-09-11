#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n, k;
	cin >> q;
	while(q--){
		cin >> n >> k;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		
		sort(a, a+n);
		
		if(a[0]+k >= a[n-1]-k) cout << a[0]+k << endl;
		else cout << "-1" << endl;
		
	}
	
	return 0;
}
