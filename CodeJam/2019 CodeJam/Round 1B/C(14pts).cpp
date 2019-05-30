#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, cnt = 1;
	cin >> T;
	int N, K;
	
	while(T--){
		cin >> N >> K;
		int c[N], d[N];
		for(int i = 0 ; i < N ; i++)
			cin >> c[i];
		for(int i = 0 ; i < N ; i++)
			cin >> d[i];
			
		long long total = 0, maxc = 0, maxd = 0;
		vector<int> cc, dd;
		for(int i = 0 ; i < N ; i++){
			for(int j = i ; j < N ; j++){
				if(c[j] > maxc) maxc = c[j];
				if(d[j] > maxd) maxd = d[j];
				cc.push_back(maxc);
				dd.push_back(maxd);
			}
			maxc = 0;
			maxd = 0;
		}
		for(int i = 0 ; i < cc.size() ; i++){
			if(abs(cc[i]-dd[i]) <= K) total++;
		}
		cout << "Case #" << cnt++ << ": " << total << '\n';
	}
	return 0;
}
