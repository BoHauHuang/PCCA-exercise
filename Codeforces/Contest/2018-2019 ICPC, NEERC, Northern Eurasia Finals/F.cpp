#include<bits/stdc++.h>
#define valid (x>0 && x<a && y>0 && y<b)
using namespace std;
long long n;

pair<long long, long long> extgcd(long long a, long long b){
	if(b==0) return {1, 0};
	int k = a/b;
	pair<long long, long long> p = extgcd(b, a-k*b);
	return {p.second, p.first-k*p.second};
}

int main(){
	cin >> n;
	
	for(long long a = 2 ; a*a <= n ; a++){
		if(!(n%a)){
			long long b = n/a;
			long long g = __gcd(a, b);
			if((n-1)%g) continue;
			
			pair<long long, long long> xy = extgcd(a, b);
			long long x = xy.first, y = xy.second;
			
			x = (x+b/g)*((n-1)/g);
			x = (x%b/g+b/g)%b/g;
			y = ((n-1)-a*x)/b;
			
			long long bx_gcd = __gcd(x, b), ay_gcd = __gcd(y, a);

			cout << "YES" << endl << "2" << endl << x/bx_gcd << " " << b/bx_gcd << endl << y/ay_gcd << " " << a/ay_gcd << endl;
			return 0;
		}
	}
	cout << "NO" << endl; 
	
	return 0;
}

