#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, l1, l2, r1, r2;
	cin >> q;
	while(q--){
		cin >> l1 >> r1 >> l2 >> r2;
		cout << l1 << " " << ((l1==r2)? l2:r2) << endl;
	}
	
	return 0;
}
