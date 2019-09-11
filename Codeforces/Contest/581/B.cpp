#include<bits/stdc++.h>
using namespace std;
long long int n, l, r;

long long int cal_max(int t){
	t--;
	long long int ans = 0, max_num = pow(2, t), now = max_num/2;
	ans += max_num*n;
	while(t--){
		ans -= (now*(t+1));
		now /= 2;
	}
	return ans;
}

long long int cal_min(int t){
	long long int ans = 0, now = 1;
	t--;
	ans += n;
	while(t--){
		ans += (now*(t+1));
		now *= 2;
	}
	return ans;
}

int main(){
	cin >> n >> l >> r;

	cout << cal_min(l) << " " << cal_max(r) << endl;

	return 0;
}
