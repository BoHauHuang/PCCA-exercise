#include<bits/stdc++.h>
using namespace std;

int main(){
	int h1, h2, m1, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	
	int one = h1*60+m1, two = h2*60+m2;
	int mid = (one+two)/2;
	int h = mid/60, m = mid%60;
	
	cout << ((h<=9)? "0" : "") << h << ":" << ((m<=9)? "0" : "") << m << endl;
	
	return 0;
}
