#include<bits/stdc++.h>
#define N 10
using namespace std;

int main(){
	int n;
	cin >> n;
	int num[n];
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];
		
	for(int i = 0 ; i< n ; i++){
		for(int j = 0 ; ; j++){
			int shift = (j<<1);
			int result = ((shift|j) & (~shift|~j));
			if((result%256) == num[i]){
				cout << j << " ";
				break;
			}
		}
	}
	
	return 0;
}
