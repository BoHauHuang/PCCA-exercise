#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
	bool p[36] = {0, 0, 1, 1, 0, 1, 
					 0, 1, 0, 0, 0, 
					 1, 0, 1, 0, 0, 
					 0, 1, 0, 1, 0, 
					 0, 0, 1, 0, 0, 
					 0, 0, 0, 1, 0, 
					 1, 0, 0, 0, 0};
	return p[n];
}

int main(){
	long long T, L, R, cnt[100010];
	memset(cnt, 0, sizeof(cnt));
	
	cin >> T;
	
	for(long long i = 1 ; i <= 100000 ; i++){
		long long num = i, total = 0;
		while(num){
			total += num%2;
			num/=2;
		}
		cnt[i] = isPrime(total) + cnt[i-1];
	}
	
	while(T--){
		cin >> L >> R;
		cout << ((L > 0)? cnt[R]-cnt[L-1] : cnt[R])<< '\n';
	}
	return 0;
}

