#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, in;
	cin >> t;

	while(t--){
		cin >> n;
		map<int, int> p;
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			p[in]++;
		}
		if(n < 3){
			cout << "0 0 0" << endl;
			continue;
		}
		int cnt = 0;
		stack<int> tmp;
		
		for(auto x : p){
			if(cnt >= ((n%2)? (n+1)/2 : n/2)) tmp.push(x.second);
			else cnt += x.second;
		}
		
		int gold = 0, silver = 0, bronze = 0;
		if(tmp.size()){
			gold = tmp.top();
			tmp.pop();
		}
		
		while(!tmp.empty()){
			if(silver <= gold) silver += tmp.top();
			else bronze += tmp.top();
			tmp.pop();
		}
		if(silver > gold && bronze > gold) cout << gold << " " << silver << " " << bronze << endl;
		else cout << "0 0 0" << endl;
	}
	
	return 0;
}
