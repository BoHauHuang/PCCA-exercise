#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int r[n], b[n], dif[n];
	bool valid = false;
	
	for(int i = 0 ; i < n ; i++)
		cin >> r[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	for(int i = 0 ; i < n ; i++)
		r[i] -= b[i];
		
	bool all_zero = true, all_neg = true;
	for(int i = 0 ; i < n ; i++){
		if(r[i] != 0) all_zero = false;
		if(r[i] > 0) all_neg = false;
 	}
		
	
	if(!all_zero && !all_neg){
		int cnt = 0, num = 0;
		
		for(int i = 0 ; i < n ; i++){
			if(r[i] > 0) cnt++;
			else if(r[i] < 0) num++;
		}
		
		cout << (num/cnt)+1 << endl;
	}
	else cout << "-1" << endl;
		
	
	
	
	return 0;
}
