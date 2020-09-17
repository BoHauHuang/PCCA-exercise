#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int a, b;
		long long ans = 0;
		priority_queue<int, vector<int>, greater<int>> ar;
		priority_queue<int> br;
		for(int i = 0 ; i < n ; i++){
			cin >> a;
			ar.push(a);
		}
		for(int i = 0 ; i < n ; i++){
			cin >> b;
			br.push(b);
		}
		
		while(k > 0 && ar.top() < br.top()){
			ar.push(br.top());
			br.push(ar.top());
			ar.pop();
			br.pop();
			k--;
		}
		
		while(!ar.empty()){
			ans += ar.top();
			ar.pop();
		}
		cout << ans << '\n';
		
	}

	return 0;
}

