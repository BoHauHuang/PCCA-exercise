#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long a[n], b[n], ar[3], br[3];
	memset(ar, 0, sizeof(ar));
	memset(br, 0, sizeof(br));
	
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		ar[i%3] += a[i];
	}
	
	for(int i = 0 ; i < n ; i++){
		cin >> b[i];
		br[i%3] += b[i];
	}
	
	long long cnt[3];
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cnt[(i+j)%3] += ar[i]*br[j];
		}
	}
	
	cout << cnt[1] << " " << cnt[2] << " " << cnt[0];
	
	return 0;
}
