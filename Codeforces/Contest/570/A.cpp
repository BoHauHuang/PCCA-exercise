#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, num;
	cin >> a;
	long long int ans;
	
	for(int i = a ; ; i++){
		num = i;
		ans = 0;
		while(num){
			ans += num%10;
			num /= 10;
		}
		if(ans%4 == 0){
			cout << i << endl;
			return 0;
		}
	}
} 
