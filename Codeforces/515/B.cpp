#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	int a[n], h[n];
	memset(h, 0, sizeof(h));
	
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(int i = 0 ; i < n ; i++){
		int low = (i-r+1 < 0)? 0 : i-r+1;
		int up = (i+r-1 >= n)? n-1 : i+r-1;
		for(int j = low ; j <= up ; j++){
			h[i] += (a[j]);
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		if(!h[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	
	int on = 0, off = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i]){
			on++;
			bool turnoff = true;
			int low = (i-r+1 < 0)? 0 : i-r+1;
			int up = (i+r-1 >= n)? n-1 : i+r-1;
			for(int j = low ; j <= up ; j++){
				if(h[j] == 1){
					turnoff = false;
					break;
				}
			}
			if(turnoff){
				off++;
				for(int j = low ; j <= up ; j++)
					h[j]--;
			}
		}
	}
	
	cout << on-off << endl;
	
	return 0;
}
