#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> LIS;
		int in, loc[n];
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			
			if(LIS.size() == 0){
				LIS.push_back(in);
				loc[i] = LIS.size()-1;
			}
			else if(in > LIS.back()){
				LIS.push_back(in);
				loc[i] = LIS.size()-1;
			}
			else{
				int pos = lower_bound(LIS.begin(), LIS.end(), in)-LIS.begin();
				LIS[pos] = in;
				loc[i] = pos;
			}
		}
		vector<int> ans;
		int now = LIS.size()-1;
		for(int i = n-1 ; i >= 0 ; i--){
			if(loc[i] == now){
				ans.push_back(i);
				now--;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for(auto x : ans)
			cout << x << " ";
		cout << endl;
	}
	
	return 0;
} 
