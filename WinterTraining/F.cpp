#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int can[n], ans = 0;
	map<int, queue<int> > cnt;
	
	for(int i = 0 ; i < n ; i++){
		cin >> can[i];
		cnt[can[i]].push(i+1);
	}
	
	sort(can, can+n, greater<int>());
	vector<int> result;
	for(int i = 0 ; i < n ; i++){
		ans += can[i]*i;
		ans += 1;
		result.push_back(cnt[can[i]].front());
		cnt[can[i]].pop();
	}
	cout << ans << endl;
	for(auto x : result)
		cout << x << " ";
	cout << endl;
	
	return 0;
}
