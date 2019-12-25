#include<bits/stdc++.h>
using namespace std;

bool valid(int n, int a, int b){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return (sum >= a && sum <= b);
}

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	long long ans = 0;
	for(int i = 1 ; i <= N ; i++)
		if(valid(i, A, B)) ans += i;
	
	cout << ans << endl;
	
	return 0;
}
