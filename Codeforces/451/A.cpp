#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	if(!(n%10)) cout << n << endl;
	else{
		long long last = n%10;
		long long front;
		if(last <= (long long)5)  front = n/10;
		else front = (n/10)+1;
		cout << front*10 << endl;
	}
	return 0;
}
