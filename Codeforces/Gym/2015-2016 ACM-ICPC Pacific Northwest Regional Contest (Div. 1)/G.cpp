#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long n, r, w, h, x, y;
	cin >> n >> r >> w >> h;
	vector<pair<long long, long long> > point;
	for(int i = 0 ; i < n ; i++){
		cin >> x >> y;
		point.push_back(make_pair((x*r+y), (r*(w-x)+y)));
	}
	sort(point.begin(), point.end());
	
	vector<long long> ans;
	for(int i = 0 ; i < point.size() ; i++){
		int pos = upper_bound(ans.begin(), ans.end(), point[i].second)-ans.begin();
		if(pos == ans.size()) ans.push_back(point[i].second);
		else ans[pos] = point[i].second;
	}
	cout << ans.size() << '\n';
	return 0;
}

