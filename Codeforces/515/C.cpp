#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	int pos[200001], left = 0, right = 0, id;
	memset(pos, 0, sizeof(pos));
	char c;
	cin >> c >> id;
	pos[id] = 0;
	left--;
	right++;
	q--;
	while(q--){
		cin >> c >> id;
		if(c == 'L'){
			pos[id] = left;
			left--;
		}
		else if(c == 'R'){
			pos[id] = right;
			right++;
		}
		else{
			cout << min(pos[id]-left-1, right-pos[id]-1) << endl;
		}
	
	}
	
	return 0;
}
