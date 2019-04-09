#include<bits/stdc++.h>
using namespace std;

int main(){
	long long T, N, K,count = 1;
	cin >> T;
	while(T--){
		cin >> N >> K;
		multiset<long long> space;
		space.insert(N);
		if(N == K) cout << "Case #" << count++ << ": 0 0" << endl;
		else{
			for(long long i = 0 ; i < K ; i++){
				long long side = *max_element(space.begin(), space.end());
				//cout << "choose: " << side << endl;
				long long L = floor((float)(side-1)/2);
				long long R = ceil((float)(side-1)/2);
				//cout << "L: " << L << "  R: " << R << endl;
				if(i == K-1) cout << "Case #" << count++ << ": " << max(L, R) << " " << min(L, R) << endl;
				else{
					multiset<long long>::iterator it;
					it = space.find(side);
					space.erase(it);
					if(L > 0) space.insert(L);
					if(R > 0) space.insert(R);
				}
			}
		}
	}
	
	return 0;
}
