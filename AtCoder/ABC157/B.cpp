#include<bits/stdc++.h>
using namespace std;
int table[3][3], vis[3][3], bvis[110], n, in;
map<int, pair<int, int> > pos;

bool Check_vis(){
	bool ans = (vis[0][0] && vis[1][1] && vis[2][2]);
	ans |= (vis[2][0] && vis[1][1] && vis[0][2]);
	
	ans |= (vis[0][0] && vis[0][1] && vis[0][2]);
	ans |= (vis[1][0] && vis[1][1] && vis[1][2]);
	ans |= (vis[2][0] && vis[2][1] && vis[2][2]);
		
	ans |= (vis[0][0] && vis[1][0] && vis[2][0]);
	ans |= (vis[0][1] && vis[1][1] && vis[2][1]);
	ans |= (vis[0][2] && vis[1][2] && vis[2][2]);
	
	return ans;
}

int main(){
	memset(vis, 0, sizeof(vis));
	memset(bvis, 0, sizeof(bvis));
	
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cin >> table[i][j];	
			bvis[table[i][j]] = 1;
			pos[table[i][j]] = make_pair(i, j);
		}
	}
	
	cin >> n;
	bool ok = false;
	
	while(n--){
		cin >> in;
		if(bvis[in]) vis[pos[in].first][pos[in].second] = 1;
		
		if(Check_vis()){
			ok = true;
			break;
		}
	}
	
	if(!ok) cout << "No" << endl;
	else cout << "Yes" << endl;

	
	return 0;
}
