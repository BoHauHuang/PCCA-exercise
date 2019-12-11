#include<bits/stdc++.h>
#define OK ((a == 1 && b == 1) || (a == 2 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 2))
using namespace std;

bool cmp(int a, int b){
	if(OK) return true;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, g;
		bool done = false;
		
		cin >> a >> b;
		if(a == 1 && b == 1){
			cout << "NO" << endl;
			done = true;
		}
		
		if(!done){
			while(a > 0 && b > 0){
				if(a == b && a%3) break;
				int tmpa = a, tmpb = b;
				
				if(a > b){
					a -= 2*(tmpa-tmpb);
					b -= (tmpa-tmpb);
				}
				else if(a < b){
					a -= (tmpb-tmpa);
					b -= 2*(tmpb-tmpa);
				}
				else{
					a = 0;
					b = 0;
					cout << "YES" << endl;
					done = true;
				}
			}
			
			if(!done) cout << ((a==0 && b==0)? "YES" : "NO") << endl;
		}
	}
	
	return 0;
}

