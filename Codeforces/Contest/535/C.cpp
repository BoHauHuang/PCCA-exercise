#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, pair<int, int> > lhs, const pair<int, pair<int, int> > rhs){ return lhs.first > rhs.first; }

int main(){
	int n;
	cin >> n;
	string land;
	map<char, int> color_to_num;
	map<int, char> num_to_color;

	color_to_num['R'] = 1;
	color_to_num['G'] = 2;
	color_to_num['B'] = 3;
	
	num_to_color[color_to_num['R']] = 'R';
	num_to_color[color_to_num['G']] = 'G';
	num_to_color[color_to_num['B']] = 'B';

	cin >> land;	

	if(n == 1) cout << "0" << endl << land[0] << endl;
	else if(n == 2 && land[0] == land[1]) cout << "1" << endl << num_to_color[(color_to_num[land[0]]+1)%3] << land[1] << endl;
	else if(n == 2 && land[0] != land[1]) cout << "0" << endl << land[0] << land[1] << endl;
	else{
		int cnt[6];
		memset(cnt,0,sizeof(cnt));
		// RGB
		for(int i = 0 ; i < n ; i++){
			if(i%3 == 0 && land[i] != 'R') cnt[0]++;
			if(i%3 == 1 && land[i] != 'G') cnt[0]++;
			if(i%3 == 2 && land[i] != 'B') cnt[0]++;	
		}
		// RBG
		for(int i = 0 ; i < n ; i++){
			if(i%3 == 0 && land[i] != 'R') cnt[1]++;
                        if(i%3 == 1 && land[i] != 'B') cnt[1]++;
                        if(i%3 == 2 && land[i] != 'G') cnt[1]++;
		}
		// GBR
		for(int i = 0 ; i < n ; i++){
                        if(i%3 == 0 && land[i] != 'G') cnt[2]++;
                        if(i%3 == 1 && land[i] != 'B') cnt[2]++;
                        if(i%3 == 2 && land[i] != 'R') cnt[2]++;
                }
		// GRB
		for(int i = 0 ; i < n ; i++){
                        if(i%3 == 0 && land[i] != 'G') cnt[3]++;
                        if(i%3 == 1 && land[i] != 'R') cnt[3]++;
                        if(i%3 == 2 && land[i] != 'B') cnt[3]++;
                }
		// BRG
		for(int i = 0 ; i < n ; i++){
                        if(i%3 == 0 && land[i] != 'B') cnt[4]++;
                        if(i%3 == 1 && land[i] != 'R') cnt[4]++;
                        if(i%3 == 2 && land[i] != 'G') cnt[4]++;
                }
		// BGR
		for(int i = 0 ; i < n ; i++){
                        if(i%3 == 0 && land[i] != 'B') cnt[5]++;
                        if(i%3 == 1 && land[i] != 'G') cnt[5]++;
                        if(i%3 == 2 && land[i] != 'R') cnt[5]++;
                }
		int m = cnt[0], idx = 0;
		for(int i = 1 ; i < 6 ; i++)
			m = min(m, cnt[i]);
		for(int i = 0  ; i < 6 ; i++)
			if(m == cnt[i]) idx = i;
		char c[3];
		if(idx == 0){
			c[0] = 'R';
			c[1] = 'G';
			c[2] = 'B';	
		}
		else if(idx == 1){
			c[0] = 'R';
			c[1] = 'B';
			c[2] = 'G';
		}
		else if(idx == 2){
			c[0] = 'G';
			c[1] = 'B';
			c[2] = 'R';
		}
		else if(idx == 3){
			c[0] = 'G';
			c[1] = 'R';
			c[2] = 'B';
		}
		else if(idx == 4){
			c[0] = 'B';
			c[1] = 'R';
			c[2] = 'G';
		}
		else if(idx == 5){
			c[0] = 'B';
			c[1] = 'G';
			c[2] = 'R';
		}
		cout << m << endl;
		for(int i = 0 ; i < n ; i++)
			cout << c[i%3];
		cout << endl;
	}

	return 0;
}
