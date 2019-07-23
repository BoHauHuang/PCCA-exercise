#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], in;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		a[i] = in+i;
	}
	sort(a, a+n);
	
	for(int i = 0 ; i < n ; i++)
		a[i] -= i;
	
	for(int i = 1 ; i < n ; i++){
		if(a[i] < a[i-1]){
			cout << ":(" << endl;
			return 0;
		}
	}
	
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl; 	
	
	return 0;
}
