#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, x1, x2, y1, y2;
	cin >> t;
	while(t--){
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << abs(x1-x2)+abs(y1-y2) << '\n';
	}
	
	return 0;
}

