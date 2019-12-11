#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin("bureau.in");
	ofstream cout("bureau.out");
	int n;
	cin >> n;
	vector<bool> status;
	
	string cmd;
	int which;
	
	stack<int> command, cancel_id;
	
	for(int i = 0 ; i < n ; i++){
		cin >> cmd;
		if(cmd == "cancel"){
			cin >> which;
			cancel_id.push(which);
		}
		command.push((cmd=="cancel")? 1:0);
		status.push_back(true);
	}
	while(!command.empty()){
		int is_cancel = command.top();
		command.pop();
		int now = command.size();
		if(is_cancel){
			int id = cancel_id.top()-1;
			cancel_id.pop();
			if(status[now]) status[id] = false;
		}
	}
	int count = 0;
	for(int i = 0 ; i < n ; i++)
		if(status[i]) count++;
	cout << count << endl;
	
	for(int i = 0 ; i < n ; i++)
		if(status[i]) cout << i+1 << " ";
	cout << endl; 
	
	return 0;
}

