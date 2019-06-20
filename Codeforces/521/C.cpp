#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a[n];
	long long int sum = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	map<long long int, long long int> result, total;
	for(int i = 0 ; i < n ; i++)
		total[a[i]]++;
	
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		long long int left = sum-a[i];
		if(!(left%2)){
			bool nonzero = (total[a[i]] != 0);
			total[a[i]] -= (total[a[i]] != 0);
			if(total[left/2]){
				cnt++;
				result[a[i]] = 1;
			}
			if(nonzero) total[a[i]]++;
		}
	}
	cout << cnt << endl;
	
	for(int i = 0 ; i < n ; i++)
		if(result[a[i]]) cout << i+1 << " ";
	cout << endl;
	
	return 0;
}
