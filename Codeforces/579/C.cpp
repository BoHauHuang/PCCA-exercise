#include<bits/stdc++.h>
using namespace std;

long long find_divisor(long long num){
	long long ans = 0;
	for(long long i = 1 ; i*i <= num ; i++)
		if(!(num%i)) ans += 2 - (i*i == num);
	return ans;
}

int main(){
	long long n, in, g = 0;
	cin >> n;
	
	for(long long i = 0 ; i < n ; i++){
		cin >> in;
		g = __gcd(in, g);
	}
	cout << find_divisor(g) << endl;
	return 0;
}
