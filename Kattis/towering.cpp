#include<bits/stdc++.h>
using namespace std;

int main(){
	int box[6], h1, h2;
	
	for(int i = 0 ; i < 6 ; i++)
		cin >> box[i];
	cin >> h1 >> h2;
	
	vector<int> ans1, ans2;
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 6 ; j++){
			if(j != i){
				for(int k = 0 ; k < 6 ; k++){
					if(k != j && k != i && box[i]+box[j]+box[k] == h1){
						ans1.push_back(box[i]);
						ans1.push_back(box[j]);
						ans1.push_back(box[k]);
						for(int m = 0 ; m < 6 ; m++)
							if(box[m] != box[i] && box[m] != box[j] && box[m] != box[k]) ans2.push_back(box[m]);
						
						sort(ans1.begin(), ans1.end(), greater<int>());
						sort(ans2.begin(), ans2.end(), greater<int>());
						for(auto x : ans1)
							cout << x << " ";
						for(auto x : ans2)
							cout << x << " ";
							
						return 0;
					}
				}
			}
		}
	}
}
