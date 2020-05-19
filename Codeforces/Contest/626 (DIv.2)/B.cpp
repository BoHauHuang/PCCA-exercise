#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int i = 0 ; i < m ; i++)
		cin >> b[i];
	
	int cnt_a[40010], cnt_b[40010], aa = 0, bb = 0;
	memset(cnt_a, 0, sizeof(cnt_a));
	memset(cnt_b, 0, sizeof(cnt_b));
	
	for(int i = 0 ; i < n ; i++){
		if(a[i] == 1){
			aa++;
			cnt_a[aa]++;
		}
		else aa = 0;
	}
	for(int i = 0 ; i < m ; i++){
		if(b[i] == 1){
			bb++;
			cnt_b[bb]++;
		}
		else bb = 0;
	}
	
	for(int i = n-1 ; i >= 0 ; i--)
		cnt_a[i] += cnt_a[i+1];
	for(int i = m-1 ; i >= 0 ; i--)
		cnt_b[i] += cnt_b[i+1];
	
	long long ans = 0;
	for(int i = 1 ; i*i <= k ; i++){
		if(k%i == 0){
			int l = i, r = k/i;
			if(l <= max(n, m) && r <= max(n, m)){
				ans += cnt_a[l]*cnt_b[r];
				if(i*i != k) ans += cnt_a[r]*cnt_b[l];
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
