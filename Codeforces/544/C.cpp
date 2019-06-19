#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	
	sort(a, a+n);
	
	int max = 1;
	for(int i = 0, j = 1; i < n && j < n ;){
		if(a[j]-a[i] <= 5){
			max = (max < j-i+1)? j-i+1 : max;
			j++;
		}
		else i++;
	}
	cout << max << endl;
	
	return 0;
} 
