#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	int heater[n];
	vector<int> heater_idx;
	for(int i = 0 ; i < n ; i++)
		cin >> heater[i];
	
	int total[n];
	memset(total, 0, sizeof(total));
	for(int i = 0 ; i < n ; i++){
		if(heater[i]){
			heater_idx.push_back(i);
			int up_bound = (i+r-1 >= n)? n-1 : i+r-1;
			int low_bound = (i-r+1 < 0)? 0 : i-r+1;
			//cout << "idx: " << i << " low: "  << low_bound << " up: " << up_bound <<endl;
			for(int j = low_bound ; j <= up_bound ; j++){
				total[j]++;
				//cout << "j: " << j <<endl;
			}		
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(!total[i]){
			heater_idx.clear();
			break;
		}
	}
	int cnt = 0;
	for(auto x : heater_idx){
		int up_bound = (x+r-1 >= n)? n-1 : x+r-1;
		int low_bound = (x-r+1 < 0)? 0 : x-r+1;
		bool close = false;
		for(int i = low_bound ; i <= up_bound ; i++){
			if(total[i] == 1) break;
			if(i == up_bound) close = true;
		}
		if(close){
			cnt++;
			for(int i = low_bound ; i <= up_bound ; i++){
				total[i]--;
			}	
		}
	}
	if(heater_idx.empty()) cout << "-1" << endl;
	else cout << heater_idx.size()-cnt << endl;
	
	return 0;
}
