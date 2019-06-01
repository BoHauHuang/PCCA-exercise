#include<bits/stdc++.h>
using namespace std;

int main(){
	int h, w, n;
	cin >> h >> w >> n;
	int brick[n];
	
	for(int i = 0 ; i < n ; i++)
		cin >> brick[i];
	
	int origin = w;
	
	for(int i = 0 ; i < n ; i++){
		if(w-brick[i] > 0) w -= brick[i];
		else if(w-brick[i] == 0){
			w = origin;
			h--;
		}
		else{
			cout << "NO" << '\n';
			return 0;
		}
		
		if(h == 0){
			cout << "YES" << '\n';
			return 0;
		}
	}
	
	cout << "NO" << '\n';
	return 0;
}
