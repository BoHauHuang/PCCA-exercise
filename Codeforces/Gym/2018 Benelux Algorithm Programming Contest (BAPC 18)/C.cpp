#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long int V, ans;
	cin >> V;
 
	ans = 4*V+2;
 
	for(long long int a = 1 ; a <= V ; a++){
		if(!(V%a)){
			for(long long int b = 1 ; b <= V/a ; b++){
				if(!((V/a)%b)){
					long long int c = (V/a)/b;
					ans = (ans > 2*(a*b+b*c+c*a))? 2*(a*b+b*c+c*a) : ans;
				}
			}
		}
	}
	
	cout << ans << endl;
	 
	return 0;
}
