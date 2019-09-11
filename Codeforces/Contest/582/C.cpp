#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int q, m, n;
	cin >> q;
	while(q--){
		cin >> n >> m;
		vector<long long int> remain;
		long long int now = m%10, sum = 0, complete = 0, left = 0;
		
		if(n == m){
			cout << m%10 << '\n';
			continue;
		}
		
		remain.push_back(now);
		now += (m%10);
		now %= 10;
		while(remain[0] != now){
			remain.push_back(now);
			now += (m%10);
			now %= 10;
		}
		
		for(int i = 0 ; i < remain.size() ; i++)
			sum += remain[i];
		complete = floor(floor(n/m)/remain.size());
		sum *= complete;

		left = (n/m)-(complete*remain.size());
		for(int i = 0 ; i < left ; i++)
			sum += remain[i];
		
		cout << sum << endl;
	}
	return 0;
}
