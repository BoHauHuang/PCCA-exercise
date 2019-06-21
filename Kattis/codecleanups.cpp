#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d[n], dirty = 0;
	for(int i = 0 ; i < n ; i++)
		cin >> d[i];
		
	int ans = 0, end= 0;
	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = i-1 ; j >= 0 ; j--){
			if(dirty+d[i]-d[j] >= 20){
				i = j+1;
				dirty = 0;
				ans++;
				break;
			}
			dirty += (d[i]-d[j]);
			if(!j) end = 1;
		}
		if(end || (!i && !end)) ans++;
		if(end) break;
	}
	
	cout << ans << endl;
	
	return 0;
}
