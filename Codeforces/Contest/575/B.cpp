#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n, k;
	cin >> q;
	while(q--){
		cin >> n >> k;
		long long int a[n];
		vector<int> idx;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if(a[i]%2) idx.push_back(i+1);
		}
		
		if(idx.size() < k || (idx.size()-k)%2) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i = 0 ; i < k-1 ; i++)
				cout << idx[i] << " ";
			cout << n << endl;
		}
	}
	
	return 0;
}
