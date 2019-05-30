#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d[n];
	for(int i = 0 ; i < n ; i++){
		cin >> d[i];
	}
	int cnt = 0, dirty = 0;
	bool end = false;
	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = i-1 ; j >= 0 ; j--){
			if(dirty+d[i]-d[j] >= 20){
				i = j+1;
				cnt++;
				dirty = 0;
				break;
			}
			dirty += d[i]-d[j];
			if(j == 0) end = true;
		}
		if((end) || (i == 0 && !end)){
			cnt++;
			break;
		}
	}
	cout << cnt << '\n';
	return 0;
}
