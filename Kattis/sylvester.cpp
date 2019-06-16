#include<bits/stdc++.h>
using namespace std;

int val(long long int n, long long int x, long long int y){
	if(n == 1) return 1;
	int v = 1;
	while(n!=1){
		n >>= 1;
		if(x < n){
			if(y >= n) y -= n;
		}
		else{
			x -= n;
			if(y >= n){
				y -= n;
				v = -v;
			}
		}
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int T;
	cin >> T;
	while(T--){
		long long int n, x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		
		for(long long int i = y ; i < y+h ; i++){
			if(w) cout << val(n, x, i);
			for(long long int j = x+1 ; j < x+w ;j++){
				cout << " " << val(n, j, i);
			}
			cout << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}
