#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) return 0;
		map<int, int> seq;
		int a[n], ans[n], in;
		
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			seq[in] = i+1;
		}
		
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		
		sort(a, a+n);
		
		int cnt = 0;
		for(auto x : seq)
			ans[x.second-1] = a[cnt++]; 
		
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << endl;
		cout << endl;
		
	}
	return 0;
}
