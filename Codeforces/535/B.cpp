#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d[n];
	
	for(int i = 0 ; i < n ; i++)
		cin >> d[i];
	
	sort(d, d+n);
	int x = d[n-1];
	map<int, int> cnt;
	for(int i = n-1 ; i >= 0 ; i--){
		if(cnt[d[i]] == 0 && d[i] > 0 && x%d[i] == 0){
			cnt[d[i]] = 1;
			d[i] = -1;
		}
	}
	sort(d, d+n);
	
	cout << x << " " << d[n-1] << endl;
	
	return 0;
}
