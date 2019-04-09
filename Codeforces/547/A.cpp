#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	
	cin >> n >> m;
	int cnt = 0;
	
	if(n == m) cout << "0" << endl;
	else if(n*2 > m && n != m) cout << "-1" << endl;
	else{
		int mul = m/n;
		while(mul > 1){
			if(mul%3 == 0){
				mul/=3;
				n*=3;
				cnt++;
			}
			else if(mul%2 == 0){
				mul/=2;
				n*=2;
				cnt++;
			}
			if(n >= m) break;
			if(mul%2 && mul%3) break;
		}
		
		if(n==m) cout << cnt << endl;
		else cout << "-1" << endl;
	}
	
	return 0;
}
