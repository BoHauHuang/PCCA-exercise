#include<bits/stdc++.h>
using namespace std;
int num[100005];

int main(){
	int T;
	cin >> T;
	while(T--){
		int in, N, K;
		cin >> N >> K;
		
		memset(num, 0, sizeof(num));
		
		for(int i = 0 ; i < N ; i++){
			cin >> in;
			num[in]++;
		}
		bool find = false;
		
		for(int i = 1 ; i <= K ; i++){
			if(K%i == 0 && num[i]){
				num[i]--;
				if(num[K/i]){
					cout << i << " " << K/i << endl;
					find = true;
				}
				num[i]++;
				if(find) break;
			}
		}
		
		if(!find) cout << "-1" << endl;
	}
	return 0;
}
