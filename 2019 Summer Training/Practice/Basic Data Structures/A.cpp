#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		if(!N) break;
		while(1){
			int in;
			queue<int> q;
			stack<int> station;
			
			cin >> in;
			if(!in){
				cout << endl;
				break;
			}
			
			q.push(in);
			for(int i = 1 ; i < N ; i++){
				cin >> in;
				q.push(in);
			}
			
			for(int i = 1 ; i <= N ; i++){
				station.push(i);
				while(!station.empty() && station.top() == q.front()){
					q.pop();
					station.pop();
				}
			}
			
			if(station.empty()) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
