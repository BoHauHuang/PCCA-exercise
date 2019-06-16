#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<int, int> find;
	int q, p[n];
	p[0] = 0;
	for(int i = 1 ; i < n ; i++){
		cin >> q;
		p[i] = p[i-1]+q;
	}
	
	int min = 200005;
	for(int i = 0 ; i < n ; i++)
		if(p[i] < min) min = p[i];
	
	for(int i = 0 ; i < n ; i++)
		find[p[i]+(1-min)] = 1;
		
	bool ok = true;
	for(int i = 1 ; i <= n ; i++)
		if(!find[i]) ok = false;
		
	if(ok){
		for(int i = 0 ; i < n ; i++)
			cout << p[i]+(1-min) << " ";
		cout << endl;
	}
	else cout << "-1" << endl;
	
	return 0;
}
