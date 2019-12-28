#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int f[n+1], from[n+1], to[n+1];
	memset(from, 0, sizeof(from));
	memset(to, 0, sizeof(to));
	for(int i = 1 ; i <= n ; i++){
		cin >> f[i];
		
		if(f[i] != 0){
			to[i] = f[i];
			from[f[i]] = i;
		}
	}
		
	queue<int> all_null, empty_to, empty_from;
	for(int i = 1 ; i <= n ; i++){
		if(to[i] == 0 && from[i] == 0) all_null.push(i);
		else if(to[i] == 0) empty_to.push(i);
		else if(from[i] == 0) empty_from.push(i);
	}
	
	while(!all_null.empty()){
		if(!empty_from.empty()){
			int send = all_null.front(), recv = empty_from.front();
			all_null.pop();
			empty_from.pop();
			empty_from.push(send);
			
			from[recv] = send;
			to[send] = recv;
		}
		else{
			int send = all_null.front();
			all_null.pop();
			int recv = all_null.front();
			all_null.pop();
			
			empty_from.push(send);
			empty_to.push(recv);
			
			from[recv] = send;
			to[send] = recv;
		}
	}
	
	while(!empty_to.empty()){
		int send = empty_to.front(), recv = empty_from.front();
		empty_to.pop();
		empty_from.pop();
		
		from[recv] = send;
		to[send] = recv;
	}
	
	for(int i = 1 ; i <= n ; i++)
		cout << to[i] << " ";
	cout << endl;
	
	return 0;
}

