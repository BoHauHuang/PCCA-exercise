#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n, in;
	map<long long, long long> cnt;
	vector<long long> edge;
	cin >> n;
	
	for(long long i = 0 ; i < n ; i++){
		cin >> in;
		cnt[in]++;
		if(cnt[in] == 2){
			edge.push_back(in);
			cnt[in] = 0;
		}
	}
	
	sort(edge.begin(), edge.end(), greater<long long>());
	
	if(edge.size() < 2) cout << "0" << endl;
	else cout << (long long)edge[0]*edge[1] << endl;
	
	return 0;
}

