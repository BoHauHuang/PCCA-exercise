#include<bits/stdc++.h>
#define bound 100000
using namespace std;
map<long long int, long long int> pos;

int main(){
	int q, n, x, y, f1, f2, f3, f4;
	cin >> q;
	while(q--){
		cin >> n;
		int left = -bound, right = bound, up = bound, down = -bound;
		
		while(n--){
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			if(!f1) left = (left < x)? x : left;
			if(!f2) up = (up > y)? y : up;
			if(!f3) right = (right > x)? x : right;
			if(!f4) down = (down < y)? y : down;
		}
		
		if(right < left || up < down) cout << "0" << endl;
		else cout << "1 " << left << " " << down << endl;
	}
	
	return 0;
}
