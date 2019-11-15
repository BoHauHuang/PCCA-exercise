#include<bits/stdc++.h>
using namespace std;
double a, b, c, d, s;
 
int main(){
	cin >> a >> b >> c >> d;
	s = (a+b+c+d)/2;
	cout << setprecision(8) << fixed << sqrt((s-a)*(s-b)*(s-c)*(s-d)) << endl; 
	
	return 0;
}
