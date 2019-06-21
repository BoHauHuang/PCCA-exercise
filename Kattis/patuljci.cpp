#include<bits/stdc++.h>
using namespace std;

int main(){
	int sum = 0, d[9];
	for(int i = 0 ; i < 9 ; i++){
		cin >> d[i];
		sum += d[i];
	}
	
	sum -= 100;
	unordered_map<int, int> id, bad;
	for(int i = 0 ; i < 9 ; i++){
		if(sum-d[i] > 0){
			if(id[sum-d[i]]){
				bad[id[sum-d[i]]-1] = 1;
				bad[i] = 1;
				break;
			}
		}
		
		id[d[i]] = i+1; 
	}
	for(int i = 0 ; i < 9 ; i++)
		if(!bad[i]) cout << d[i] << endl;
	
	return 0;
}
