#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int age_cnt[20], candy_cnt[60];
		memset(age_cnt, 0, sizeof(age_cnt));
		memset(candy_cnt, 0, sizeof(candy_cnt));
		
		int N, M, in, age_min = 20;
		cin >> N >> M;
		for(int i = 0 ; i < N ; i++){
			cin >> in;
			age_cnt[in]++;
			if(age_min > in) age_min = in;
		}
		for(int i = 0 ; i < M ; i++){
			cin >> in;
			candy_cnt[in]++;
		}
		
		vector<int> idx, age;
		bool find = false;
		for(int j = 0 ; j < 60 ; j++){
			if(candy_cnt[j] >= age_cnt[age_min]){
				find = true;
				idx.push_back(j);
			}
		}
		if(!find){
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0 ; i < 20 ; i++)
			if(age_cnt[i]) age.push_back(age_cnt[i]);
			
		bool done = false;
		for(int i = 0 ; i < idx.size() ; i++){
			int a = 0;
			for(int j = idx[i] ; j < 60 ; j++){
				if(candy_cnt[j] >= age[a]) a++;
				
				if(a == age.size()){
					cout << "YES" << endl;
					done = true;
				}
				if(done) break;
			}
			if(done) break;
		}
		
		if(!done) cout << "NO" << endl;
	}
	
	return 0;
}
