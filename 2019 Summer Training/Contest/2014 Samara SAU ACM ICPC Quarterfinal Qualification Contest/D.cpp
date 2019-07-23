#include<bits/stdc++.h>
using namespace std;
int n, m, pos, val;
 
int main(){
	cin >> n;
	int cnt = 0, a[n];
	map<int, int> num;
	bool valid = false;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		num[a[i]]++;
	}
	
	if(num[a[0]] == n){
		cout << "0" << endl;
		return 0;
	}
	
	cin >> m;
	while(m--){
		cin >> pos >> val;
		num[a[pos-1]]--;
		a[pos-1] = val;
		num[a[pos-1]]++;
		cnt++;
		if(num[a[pos-1]] == n){
			valid = true;
			break;
		}
	}
	
	if(!valid) cout << "-1" << endl;
	else cout << cnt << endl;
	
	return 0;
}
