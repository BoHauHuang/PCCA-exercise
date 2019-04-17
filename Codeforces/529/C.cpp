#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<long long> num(k, 1);
	long long sum = k;
	
	for(int i = 0 ; i < k ; i++){
		while(1){
			if(sum + num[i] <= n){
				sum += num[i];
				num[i] *= 2;
			}
			else break;
		}
	}
	if(sum == n){
		cout << "YES" << endl;
		for(auto x : num){
			cout << x << " ";
		}
		cout << endl;
	}
	else cout << "NO" << endl;	
	return 0; 
} 
