#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, P, K, L, count = 1;
	cin >> N;
	while(N--){
		cin >> P >> K >> L;
		int total = (P*K > 1000)? 1000 : P*K, in;
		vector<long long int> t(total, 0);
		
		for(int i = 0 ; i < L ; i++){
			cin >> in;
			t[i] = in;
		}
		
		sort(t.begin(), t.end(), greater<long long int>());
		long long int ans = 0, cnt = 1, n = 0;
		
		for(int i = 0 ; i < t.size() ; i++){
			if(n < K){
				ans += (cnt*t[i]);
				n++;
				if(n == K) cnt++, n = 0;
			}
		}
		
		cout << "Case #" << count++ << ": " << ans << endl;
	}
	
	return 0;
}
