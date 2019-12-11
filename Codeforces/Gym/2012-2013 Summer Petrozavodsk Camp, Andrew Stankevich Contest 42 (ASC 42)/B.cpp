#include<bits/stdc++.h>
using namespace std;
int n, s, t;
double p;

double cal(int money, int t){
	if(money >= n) return 1;
	if(!money || !t) return 0;
	
	return p*cal(money+min(money, n-money), t-1)+(1.0-p)*cal(money-min(money, n-money), t-1);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ifstream cin("betting.in");
	ofstream cout("betting.out");
	
	while(cin >> n >> s >> p >> t){
		if(n == 0 && s == 0 && p == 0 && t == 0) break;
		p /= 100.0;
		cout << fixed << setprecision(10) << cal(s, t) << '\n';
	}
	
	return 0;
}

