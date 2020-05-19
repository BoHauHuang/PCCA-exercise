#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		long long ans[k];
		bool yes = false;
		
		memset(ans, 0, sizeof(ans));
		
		// even
		if(n-2*k >= 0){
			long long now = n-2*k;
			if(now%2 == 0) yes = true;
			
			if(yes){
				cout << "YES" << endl;
				cout << now+2 << " ";
				for(int i = 1 ; i < k ; i++)
					cout << "2 ";
				cout << endl;
			}
		}
		
		// odd
		if(!yes && n-k >= 0){
			long long now = n-k;
			if(now%2 == 0) yes = true;
			
			if(yes){
				cout << "YES" << endl;
				cout << now+1 << " ";
				for(int i = 1 ; i < k ; i++)
					cout << "1 ";
				cout << endl;
			}
		}
		
		if(!yes) cout << "NO" << endl;
		
	}

	return 0;
}

