#include<bits/stdc++.h>
using namespace std;

long long min_area;
long long x[3], y[3];

long long maxx(long long a, long long b , long long c){
	return max(a, max(b, c));
}

void cal(long long x[], long long y[]){
	min_area = min(min_area, (x[0]+x[1]+x[2])*maxx(y[0], y[1], y[2]));
	min_area = min(min_area, max(x[0]+x[1], x[2])*(max(y[0], y[1])+y[2]));
}

void fnc(int a, int b, int c, long long x[], long long y[]){
	long long tmpa[3], tmpb[3];
	for (int i = 0; i < 3; i++) {
		tmpa[i] = x[i];
		tmpb[i] = y[i]; 	
	}
	x[a] = tmpa[0];
	x[b] = tmpa[1];
	x[c] = tmpa[2];
	y[a] = tmpb[0];
	y[b] = tmpb[1];
	y[c] = tmpb[2];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		
		for(int i = 0 ; i < 3 ; i++){
			cin >> x[i] >> y[i];
			if(y[i] > x[i]) swap(x[i], y[i]);
		}
		
		min_area = max(max(x[0], x[1]), x[2])*(y[0]+y[1]+y[2]);
		min_area = min(min_area, max(max(y[0], y[1]), y[2])*(x[0]+x[1]+x[2]));
		long long ttx[3], tty[3];
		for(int p = 0 ; p < 3 ; p++){
			ttx[p] = x[p];
			tty[p] = y[p];
		}
		for(int k = 0 ; k < 6 ; k++){
			
			if(k == 0) fnc(0, 1, 2, x, y);
			if(k == 1) fnc(0, 2, 1, x, y);
			if(k == 2) fnc(1, 0, 2, x, y);
			if(k == 3) fnc(1, 2, 0, x, y);
			if(k == 4) fnc(2, 1, 0, x, y);
			if(k == 5) fnc(2, 0, 1, x, y);
			
			for(int i = 0 ; i < 8 ; i++){
				for(int j = 0 ; j < 3 ; j++){
					if(i&(1<<j)) swap(x[j], y[j]);
				}
				cal(x, y);
				for(int j = 0 ; j < 3 ; j++){
					if(i&(1<<j)) swap(x[j], y[j]);
				}
			}
			for(int p = 0 ; p < 3 ; p++){
				x[p] = ttx[p];
				y[p] = tty[p];
			}
		}
		cout << min_area << endl;
	}
	
	return 0;
}
