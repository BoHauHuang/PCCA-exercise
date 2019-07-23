#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int a, b, c;
	bool in_ab = false;
	cin >> a >> b >> c;
	for(int i = a ; i <= b ; i++){
		if(c == i){
			in_ab = true;
			break;
		}
	}
	
	if(b >= 2*c || in_ab) cout << "Take another envelope" << endl;
	else cout << "Stay with this envelope" << endl;
	
}
