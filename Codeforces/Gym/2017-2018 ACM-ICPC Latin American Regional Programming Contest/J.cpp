#include<bits/stdc++.h>
using namespace std;
map<int, int> cnt, g_ok;
 
int main(){
	string s;
	int n;
	cin >> s;
	n = s.size();
	vector<int> bad;
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] == 'P') bad.push_back(i);
 
	for(int i = 1 ; i < n ; i++){
		cnt[__gcd(i, n)]++;
	}
	int ans = 0;
 
	for(auto x : cnt){
		int g = x.first;
 
		int ok[g];
		memset(ok, 0, sizeof(ok));
		for(auto idx : bad){
			ok[idx%g]++;
		}
		for(int i = 0 ; i < g ; i++){
			if(ok[i] == 0){
				ans+=x.second;
				break;
			}
		}
	}
 
	cout << ans << '\n';
 
	return 0;
}
