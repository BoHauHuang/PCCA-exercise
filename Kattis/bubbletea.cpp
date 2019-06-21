#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N;
	int tea[N];
	if(!N){
		cout << "0" << endl;
		return 0;
	} 
	for(int i = 0 ; i < N ; i++)
		cin >> tea[i];
	cin >> M;
	int topping[M];
	if(!M){
		cout << "0" << endl;
		return 0;
	} 
	for(int i = 0 ; i < M ; i++)
		cin >> topping[i];
	
	bool nonzero = false;
	long long int kind, min = 1000000000;
	for(int i = 0 ; i < N ; i++){
		cin >> kind;
		while(kind--){
			int in;
			nonzero = true;
			cin >> in;
			int cost = tea[i]+topping[in-1];
			if(min > cost) min = cost;
		}
	}
	if(!nonzero){
		cout << "0" << endl;
		return 0;
	}
	long long int money;
	cin >> money;
	cout << (((money/min)-1 < 0)? 0 : (money/min)-1) << endl;
	return 0;
}
