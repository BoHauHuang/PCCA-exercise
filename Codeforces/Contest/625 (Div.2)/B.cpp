#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> lhs, pair<long long, long long> rhs){
	return lhs.first < rhs.first;
}

int main(){
	long long n;
	cin >> n;
	long long b[n], tmp[n];
	for(long long i = 0 ; i < n ; i++){
		cin >> b[i];
		tmp[i] = b[i];
	}
	vector<pair<long long, long long> > vis;
	
	if(n == 1) cout << b[0] << endl;
	else{
		for(long long i = 0 ; i < n ; i++)
			tmp[i] -= i;
		for(long long i = 0 ; i < n ; i++)
			vis.push_back(make_pair(tmp[i], b[i]));
			
		sort(vis.begin(), vis.end(), cmp);
		
		long long ans = 0, sum = 0, now = vis[0].first;
		for(long long i = 0 ; i < vis.size() ; i++){
			if(now != vis[i].first){
				if(ans < sum) ans = sum;
				sum = vis[i].second;
				now = vis[i].first;
			}
			else sum += vis[i].second;
		}
		if(ans < sum) ans = sum;
		cout << ans << endl;
	}
	
	return 0;
}
