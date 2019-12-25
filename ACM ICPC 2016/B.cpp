#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
typedef double lol;

lol n, t;
vector<pair<lol, lol> > nodes;

lol dis(pair<lol, lol> lhs, pair<lol, lol> rhs){
	return sqrt((lhs.F-rhs.F)*(lhs.F-rhs.F)+(lhs.S-rhs.S)*(lhs.S-rhs.S));
}

void init(){
	nodes.clear();
	cin >> n;
}

int main(){
	cin >> t;
	while(t--){
		init();
		
		for(lol i = 0 ; i < n ; i++){
			lol a, b;
			cin >> a >> b;
			nodes.push_back(make_pair(a, b));
		}
		lol ans = INF;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(i!=j) ans = min(ans, dis(nodes[i], nodes[j]));
			}
		}
		ans = (long long)(ans*100);
		cout << fixed << setprecision(2) << (double)ans/100 << endl;
	}
	
	return 0;
}
