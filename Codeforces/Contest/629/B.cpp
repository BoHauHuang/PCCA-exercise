#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		
		bool three = false;
		
		for(int left = 0 ; left < n ; left++){
			for(int right = left+2 ; right < n ; right++){
				if(a[left] == a[right]){
					three = true;
					break;
				}
			}
		}
		
		if(three) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

