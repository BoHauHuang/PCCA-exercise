#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n){
		long long a[n+2], max_left[n+2], max_right[n+2], sum = 0;
		vector<long long> ans;
		memset(max_left, 0, sizeof(max_left));
		memset(max_right, 0, sizeof(max_right));
		
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
			sum += a[i];
		}
		max_left[0] = -1e11;
		max_right[n+1] = -1e11;
		
		for(int i = 1 ; i <= n ; i++)
			max_left[i] = (max_left[i-1] > a[i])? max_left[i-1] : a[i];
		
		for(int i = n ; i >= 1 ; i--)
			max_right[i] = (max_right[i+1] > a[i])? max_right[i+1] : a[i];
		
		for(int i = 1 ; i <= n ; i++){
			long long max = (max_left[i-1] > max_right[i+1])? max_left[i-1] : max_right[i+1];
			if(max*2 == sum-a[i]) ans.push_back(i);
		}
		cout << ans.size() << endl;
		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
