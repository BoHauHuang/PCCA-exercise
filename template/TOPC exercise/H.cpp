#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;

set<int> s;
int n, big, small = INF;
map<int, int> vis;
 
void init() {
	big = 0;
	s.clear();
}
 
int main() {
	init();
	cin >> n;
	bool even = true;
	int g = 0;
	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		if(x%2) even = false;
		if(!g) g = x;
		vis[x] = 1;
		g = __gcd(g, x);
		
		big = max(big, x);
		small = min(small, x);
		s.insert(x);
	}
	if(!even){
		int ans = big - (int) s.size();
		cout << (ans % 2 ? "Alice" : "Bob") << '\n';
	}
	else{
		int ans = big/g - s.size();
		cout << (ans % 2 ? "Alice" : "Bob") << '\n';
	}
 
	return 0;
}
