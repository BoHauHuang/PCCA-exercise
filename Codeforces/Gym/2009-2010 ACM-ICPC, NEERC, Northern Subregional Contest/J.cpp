#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 65
 
lol a, b, p, q;
lol aa[MAX+1][MAX+1], bb[MAX+1][MAX+1];
 
void build() {
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	aa[0][0] = a-1;
	bb[0][0] = b;
	
	for(int i = 0 ; i < MAX ; i++){
		if(i != 0) aa[i][0] = aa[i-1][0]/p;
		if (aa[i][0] == 0) break;
		
		for(int j = 1 ; j < MAX ; j++)
			aa[i][j] = aa[i][j-1]/q;
	}
	
	for(int i = 0 ; i < MAX ; i++){
		if(i != 0) bb[i][0] = bb[i-1][0]/p;
		if(bb[i][0] == 0) break;
		 
		for(int j = 1 ; j < MAX ; j++)
			bb[i][j] = bb[i][j-1]/q;
	}
}
 
int main() {
	ifstream cin ("jealous.in");
	ofstream cout("jealous.out");

	cin >> a >> b >> p >> q;
	build();
	
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			aa[i][j] = aa[i][j]-(aa[i+1][j]+aa[i][j+1])+aa[i+1][j+1];
			bb[i][j] = bb[i][j]-(bb[i+1][j]+bb[i][j+1])+bb[i+1][j+1];
		}
	}
	
	lol cnt = 0;
	for(int i = 1 ; i <= MAX ; i++){
		for(int j = 0 ; j < i ; j++){
			cnt += bb[i][j]-aa[i][j];
		}
	}
	cout << cnt << endl;
 
	return 0;
}
