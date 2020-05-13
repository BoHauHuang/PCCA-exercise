#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n.size() < 2) cout << "1 " << n << endl;
		else{
			int ans = 0;
			for(int i = 0 ; i < n.size() ; i++)
				if(n[i] > '0' && n[i] <= '9') ans++;
				
			cout << ans << endl;
			for(int i = 0 ; i < n.size() ; i++){
				if(n[i] > '0'){
					cout << n[i];
					for(int j = 0 ; j < n.size()-i-1 ; j++){
						cout << "0";
					}
					cout << " ";	
				}
			}
		}
	}


	return 0;
}

