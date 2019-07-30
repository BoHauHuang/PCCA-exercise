#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T, n, m, count = 1;
	cin >> T;
	while(T--){
		cin >> n; getchar();
		
		string s;
		pair<int, int> a[n+1];
		for(int i = 0 ; i < n ; i++){
			getline(cin , s);
			a[i] = make_pair((int)s[0]-'a', (int)s[s.size()-1]-'a');
		}
		scanf("%d", &m);
		getchar();
		
		pair<int, int> b[m+1];
		for(int i = 0 ; i < m ; i++){
			getline(cin , s);
			b[i] = make_pair((int)s[0]-'a', (int)s[s.size()-1]-'a');
		}
		
		bool win = false;
		for(int i = 0 ; i < n ; i++){
			int k = 0;
			for(int j = 0 ; j < m ; j++){
				if(a[i].second == b[j].first) k = 1;
			}
			if(!k) win = true;
		}
		
		cout << "Game " << count++ << ": " << ((win)? "player1" : "player2") << endl;
	}
	
	return 0;
}
