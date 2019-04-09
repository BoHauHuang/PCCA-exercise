#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int L, v, l, r;
	while(t--){
		cin >> L >> v >> l >> r;
		int total = L/v;
		int start = ceil((double)l/v);
		int end = r/v;
		int sum = end - start + 1;
		//cout << "start: " << start << endl << "end: " << end << endl << "sum: " << sum << endl;
		cout << total-sum << endl;
	}
	
	return 0;
}
