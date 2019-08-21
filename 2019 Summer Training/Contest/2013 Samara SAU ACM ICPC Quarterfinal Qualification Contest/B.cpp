#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, ans = 0;
	cin >> n;
	string s[n];
	map<vector<int>, long long int> equ;
	for(int i = 0 ; i < n ; i++)
		cin >> s[i];
	
	for(int i = 0 ; i < n ; i++){
		long long int vis[27], c = 1;
		vector<int> cnt;
		memset(vis, 0, sizeof(vis));
		for(int j = 0 ; j < s[i].size() ; j++){
			if(vis[s[i][j]-'a'] == 0) vis[s[i][j]-'a'] = c++;
			cnt.push_back(vis[s[i][j]-'a']);
		}
		equ[cnt]++;
	}
	
	for(auto x : equ){
		long long int total = x.second;
		ans += total*(total-1)/2;
	}
	cout << ans << endl; 
	
	return 0;
}
