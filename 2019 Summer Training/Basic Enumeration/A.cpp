#include<bits/stdc++.h>
using namespace std;

double p, a, b, c, d, pr[1000005], m[1000005];

double price(double k){ return p*(sin(a*k+b)+cos(c*k+d)+2); }

int main(){	
	int n;
	while(cin >> p >> a >> b >> c >> d >> n){
		double max = 0;
		
		memset(pr, 0, sizeof(pr));
		memset(m, 0, sizeof(m));
		
		for(int i = 1 ; i <= n ; i++)
			pr[i] = price(i);
			
		m[n] = pr[n];
		
		for(int i = n-1 ; i >= 1 ; i--)
			m[i] = (pr[i] > m[i+1])? m[i+1] : pr[i];
		
		for(int i = 1 ; i <= n ; i++)
			if(max < pr[i]-m[i]) max = pr[i]-m[i];
		
		printf("%.7lf\n", max);
	}
	
	return 0;
}
