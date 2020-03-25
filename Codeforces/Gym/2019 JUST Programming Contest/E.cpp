#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector<int>v;
		vector<int>mi;
		int sum = 0;
		for (int i = 0 ; i < n ; i++) {
			int add;
			cin >> add;
			v.push_back(add);
			sum += add;
			if(add < 0) {
				mi.push_back(add);
			}
			v[i] = abs(v[i]);
		}
		sort(v.begin(),v.end());
		sort(mi.begin(),mi.end());
		for (int i = 0 ; i < min(k,(int)mi.size());i++) {
			sum -= 2 * mi[i];
		}
		if (k > mi.size() && ((k-mi.size())&1)){
			sum -= v[0];
		}
		cout << sum << endl;
	}

	return 0;
}

