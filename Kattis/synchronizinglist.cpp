#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, cnt = 0;
	while(cin >> n){
		if(!n) break;
		if(cnt) cout << '\n';
		cnt++;
		int first[n], second[n];
		for(int i = 0 ; i < n ; i++)
			cin >> first[i];
		for(int i = 0 ; i < n ; i++)
			cin >> second[i];
		
		vector<int> f(first, first+sizeof(first)/sizeof(int));
		vector<int> s(second, second+sizeof(second)/sizeof(int));
		sort(f.begin(), f.end());
		sort(s.begin(), s.end());
		
		int order[n];
		memset(order, 0, sizeof(order));
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < f.size() ; j++){
				if(first[i] == f[j]){
					order[i] = j;
					break;
				}
			}
		}
		
		for(int i = 0 ; i < n ; i++)
			cout << s[order[i]] << '\n';
		
	}
	return 0;
}
