#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N;
	if(!N){
		cout << "0" << '\n';
		return 0;
	}
	int tea_price[N];
	for(int i = 0 ; i < N ; i++){
		cin >> tea_price[i];
	}
	cin >> M;
	if(!M){
		cout << "0" << '\n';
		return 0;
	}
	int top_price[M];
	for(int i = 0 ; i < M ; i++){
		cin >> top_price[i];
	}
	bool s = false;
	int min, k, type;
	for(int i = 0 ; i < N ; i++){
		cin >> k;
		while(k--){
			cin >> type;
			int cost = top_price[type-1]+tea_price[i];
			if(!s){
				s = true;
				min = cost;
			}
			if(min > cost) min = cost;
		}
	}
	if(!s){
		cout << "0" << '\n';
		return 0;
	}
	int money;
	cin >> money;
	int ans = floor((double)money/min)-1;
	if(ans > 0) cout << ans << '\n';
	else cout << "0" << '\n';
	return 0;
}
