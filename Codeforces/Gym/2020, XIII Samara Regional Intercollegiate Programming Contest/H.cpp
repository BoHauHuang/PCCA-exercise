#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int deg[n+1], u, v, one_deg = 0;
	memset(deg, 0, sizeof(deg));
	for(int i = 1 ; i < n ; i++){
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	
	for(int i = 1 ; i <= n ; i++)
		one_deg += (deg[i]==1);
	
	cout << ((one_deg%2)? (one_deg+1)/2 : one_deg/2) << '\n';
	
	return 0;
}

