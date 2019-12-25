#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		deque<int> p;
		int in, ans[n+1];
		memset(ans,0,sizeof(ans));
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			p.push_back(in);
		}
		
		int now = n;
		if(p.size() == now) ans[now] = 1;
		
		while(p.size() > 1){
			if(p.size() == now) ans[now] = 1;
			if(p.front() > p.back()){
				now = min(now, p.front()-1);
				p.pop_front();
			}
			else{
				now = min(now, p.back()-1);
				p.pop_back();
			}
		}
		ans[1] = 1;
		
		for(int i = 1 ; i <= n ; i++)
			cout << ans[i];
		cout << endl; 
	}
	
	
	return 0;
}
