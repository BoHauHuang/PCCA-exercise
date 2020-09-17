#include<bits/stdc++.h>
using namespace std;
struct comparitor{
	bool operator()(pair<int, int> lhs, pair<int, int> rhs) const{
		if(lhs.second-lhs.first == rhs.second-rhs.first) return lhs.first > rhs.first;
		return (lhs.second-lhs.first < rhs.second-rhs.first);
	}
};

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
	
		priority_queue<pair<int, int>, vector<pair<int, int>>, comparitor > interval;
		interval.push(make_pair(1, n));
		int mid, ans[n+1];
		memset(ans, 0 , sizeof(ans));
		
		for(int i = 1 ; i <= n ; i++){
			pair<int, int> f = interval.top();
			interval.pop();
			mid = (f.first+f.second)>>1;
			ans[mid] = i;
			
			if(mid > f.first) interval.push(make_pair(f.first, mid-1));
			if(mid < f.second) interval.push(make_pair(mid+1, f.second));
		}
		for(int i = 1 ; i <= n ; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	
	return 0;
}

