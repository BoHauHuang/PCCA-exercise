#include<bits/stdc++.h>
using namespace std;
int g_in_q[1005];
int id_in_q[1000005];
queue<int> group_q;
deque<int> id_q[1005];
unordered_map<int, int> id_to_g;

void enqueue(int id){
	if(id_in_q[id]) return;
	else{
		int group = id_to_g[id];
		if(g_in_q[group] == 0){
			group_q.push(group);
			id_q[group].push_back(id);
			id_in_q[id] = 1;
			g_in_q[group] = 1;
		}
		else{
			if(id_in_q[id] == 0){
				id_q[group].push_back(id);
				id_in_q[id] = 1;
			}
		}
	}
	return;
}

void dequeue(){
	int group = group_q.front();
	cout << id_q[group].front() << '\n';
	id_q[group].pop_front();
	if(id_q[group].empty()) group_q.pop();
	return;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, count = 1;
	while(cin >> t){
		if(!t) break;
		int g[t], in;	
		
		id_to_g.clear();
		memset(g_in_q, 0, sizeof(g_in_q));
		memset(id_in_q, 0, sizeof(id_in_q));
		
		for(int i = 0 ; i < t ; i++){
			cin >> g[i];
			for(int j = 0 ; j < g[i] ; j++){
				cin >> in;
				id_to_g[in] = i+1;
			}
		}
		int id;
		string cmd;
		cout << "Scenario #" << count++ << '\n';
		while(cin >> cmd){
			if(cmd == "STOP") break;
			if(cmd == "ENQUEUE"){
				cin >> id;
				enqueue(id);
			}
			if(cmd == "DEQUEUE") dequeue();
		}
	}
	return 0;
}
