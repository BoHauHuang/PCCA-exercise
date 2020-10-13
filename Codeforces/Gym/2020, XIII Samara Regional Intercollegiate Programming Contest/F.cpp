#include <bits/stdc++.h>
using namespace std;
 
int main() {
	vector<int> v;
	v.clear();
 
	int n; cin >> n;
	for (int i = 1; i <= n; i+= 2) v.push_back(i);
 
	if (n % 2 == 0) v.push_back(n);
 
	cout << v.size() << '\n';
	for (auto i : v) cout << i << ' ';
	cout << '\n'; 
	
	return 0;
}
