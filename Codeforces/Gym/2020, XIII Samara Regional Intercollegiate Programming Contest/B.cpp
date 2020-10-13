#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, t;
	cin >> n >> t;

	long long x[n], zero = 0;
	vector<long long> neg, pos;
	
	for(int i = 0 ; i < n ; i++){
		cin >> x[i];
		if(x[i] > 0) pos.push_back(x[i]);
		else if(x[i] < 0) neg.push_back(abs(x[i]));
		else zero++;
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	
	long long ans = 0;
	for(int i = 0 ; i < pos.size() ; i++){
		if(pos[i] > t) break;
		long long r = t-2*pos[i], nl = 0;
		if(r > 0) nl = upper_bound(neg.begin(), neg.end(), r)-neg.begin();
		ans = max(i+nl+1, ans);
	}
	for(int i = 0 ; i < neg.size() ; i++){
		if(neg[i] > t) break;
		long long r = t-2*neg[i], pl = 0;
		if(r > 0) pl = upper_bound(pos.begin(), pos.end(), r)-pos.begin();
		
		ans = max(i+pl+1, ans);
	}
	
	cout << ans+zero << '\n';
	
	return 0;
}

