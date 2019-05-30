#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int ng, nm;
		cin >> ng >> nm;
		
		int in;
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
		
		while(g.size() > 0 && m.size() > 0){
			int gf = g.front(), mf = m.front();
			
			if(gf >= mf) m.pop_front();
			else if(gf < mf) g.pop_front();
		}
		if(g.size() == 0) cout << "MechaGodzilla" << '\n';
		else if(m.size() == 0) cout << "Godzilla" << '\n';
		else cout << "uncertain" << '\n';
	}
	return 0;
}
