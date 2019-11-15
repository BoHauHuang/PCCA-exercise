#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n, in;
	cin >> q;
	while(q--){
		cin >> n;
		vector<int> p;
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			p.push_back(in);
		}
		
		vector<int> tmp = p;
		for(int i = 0 ; i < p.size() ; i++)
			tmp.push_back(p[i]);
		
		bool one = false, yes_1 = false, last = false, yes_2 = false;
		int cnt = 1;
		for(int i = 0 ; i < tmp.size() ; i++){
			if(!one && tmp[i] == 1){
				one = true;
				cnt = 1;
			}
			if(one && tmp[i] == cnt) cnt++;
			else if(one && tmp[i] != cnt) one = false;
			
			if(cnt == n+1){
				yes_1 = true;
				break;
			}
		}
		cnt = n;
		for(int i = 0 ; i < tmp.size() ; i++){
			if(!last && tmp[i] == n){
				last = true;
				cnt = n;
			}
			if(last && tmp[i] == cnt) cnt--;
			else if(last && tmp[i] != cnt) last = false;
			
			if(cnt == 0){
				yes_2 = true;
				break;
			}
		}
		
		if(yes_1 || yes_2) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}	
	
	return 0;
} 
