#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while(t--){
		int cnt = 0;
		priority_queue<int>pq;
		for(int i = 0 ; i < 3 ; i++) {
			string s;
			cin >> s;
			int z = 0;
			for (auto j:s) {
				if(j=='1') {
					cnt++;
				}
				else {
					z++;
				}
			}
			if (z) {
				pq.push(z);
			}
		}
		if (cnt <= 10) {
			cout << string(cnt,'1')<<string(10-cnt,'0')<<'\n';
		}
		else {
			while(pq.size() >= 2) {
				int now = pq.top();
				pq.pop();
				int now2 = pq.top();
				pq.pop();
				now--,now2--;
				if(now) {
					pq.push(now);
				}
				if(now2) {
					pq.push(now2);
				}
			}
			int z;
			if (!pq.size()) {
				z = 0;
			}
			else {
				z = pq.top();
			}
			cout << string(10-z,'1') <<string(z,'0')<<'\n';
		}
	}
	return 0;
}

