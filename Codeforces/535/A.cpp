#include<bits/stdc++.h>
using namespace std;

int main(){
	int Q;
	cin >> Q;
	while(Q--){
		int L1, L2, R1, R2;
		cin >> L1 >> R1 >> L2 >> R2;
		if(L1 != R2) cout << L1 << " " << R2 << endl;
		else cout << L1 << " " << L2 << endl;
	}

	return 0;
}
