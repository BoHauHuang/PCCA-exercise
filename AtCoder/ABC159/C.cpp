#include<bits/stdc++.h>
using namespace std;

int main(){
	double L, a, b, c;
	cin >> L;
	
	a = L/3;
	b = L/3;
	L -= (a+b);
	c = L;
	
	cout << fixed << setprecision(10) << a*b*c << endl;
	
	return 0;
}
