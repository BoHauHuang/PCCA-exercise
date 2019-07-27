#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, dmg = 0, t, d, ans = 0;
	cin >> n;
	priority_queue<int> meteor;
	
	for(int i = 0 ; i < n ; i++){
		cin >> t >> d;
		dmg += d;
		meteor.push(d);
		if(dmg > t){
			dmg -= meteor.top();
			meteor.pop();
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
