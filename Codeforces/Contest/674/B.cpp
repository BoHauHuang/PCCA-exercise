#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int all_same = 0, left_dia = 0, right_dia = 0, mess = 0, x[4];
		for(int i = 0 ; i < n ; i++){
			cin >> x[0] >> x[1] >> x[2] >> x[3];
			if(x[0] == x[1] && x[1] == x[2] && x[2] == x[3]) all_same++;
			else if(x[0] == x[3] && x[1] == x[2]){
				left_dia++;
				right_dia++;
			}
			else if(x[0] != x[3] && x[1] == x[2]) left_dia++;
			else if(x[0] == x[3] && x[1] != x[2]) right_dia++;
			else mess++;
		}
		
		if((all_same || (left_dia && right_dia) || (left_dia)) && m%2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

