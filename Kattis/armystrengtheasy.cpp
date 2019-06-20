#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, ng, nm, in;
	cin >> T;
	while(T--){
		cin >> ng >> nm;
		deque<int> g, m;
		
		for(int i = 0 ; i < ng ; i++){
			cin >> in;
			g.push_back(in);
		}
		for(int i = 0 ; i < nm ; i++){
			cin >> in;
			m.push_back(in);
		}
		sort(g.begin(), g.end());
		sort(m.begin(), m.end());
		
		while(g.size() && m.size()){
			if(g.front() < m.front()) g.pop_front();
			else m.pop_front();
		}
		
		cout << ((m.size())? "MechaGodzilla" : "Godzilla") << endl;
		
	}
	return 0;
}
