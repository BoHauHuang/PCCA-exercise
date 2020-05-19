#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int grid[n][m];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				cin >> grid[i][j];
		map<int,int>last;
		int ans = 0;
		for(int i = 0 ; i < m ; i++) {
			last[grid[0][i]]++;
		}
		for(int i = 1 ; i < n ; i++) {
			map<int,int>cur;
			for (int j = 0 ; j < m ; j++) {
				cur[grid[i][j]]++;
			}
			for (auto j:cur) {
				ans += min(j.second,last[j.first]);
			}
			last = cur;
		}
		cout << ans << endl;
	}
	return 0;
}
