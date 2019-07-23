#include<bits/stdc++.h>
using namespace std;
long long h[1000010];
 
int main(){
	long long n, in, low, high = 0;
	cin >> n;
	
	memset(h, 0, sizeof(h));
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		h[in]++;
		if(i) low = (low > in)? in : low;
		else low = in;
		
		high = (high < in)? in : high;
	}
	
	for(int i = low+1 ; i <= high ; i++)
		h[i] += h[i-1];
	
	long long min = n; 
	
	for(int i = low ; i <= high ; i++){
		int more = h[high]-h[i];
		min = (more+i < min)? more+i : min;
	}
	
	cout << min << endl;
	
	return 0;
}
