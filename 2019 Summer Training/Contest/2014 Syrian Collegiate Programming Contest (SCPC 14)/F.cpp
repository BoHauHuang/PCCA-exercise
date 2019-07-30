#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T, count = 1;
	cin >> T;
	while(T--){
		long long int n, m;
		cin >> n >> m;
		cout << "Case " << count++ << ": ";
		long long int left = 0, right = n;
		if(m == 1){
			cout << "0 0" << endl;
			continue;
		}
		while(left < right){
			long long int mid = (left+right)/2;
			if(mid*(mid+1)/2 > m) right = mid;
			else if(mid*(mid+1)/2 < m) left = mid+1;
			else{
				left = mid;
				right = mid;
				break;
			}
		}
		m--;
		cout << left-1 << " " << m-((left-1)*left/2) << endl;
	}
	
	return 0;
}
