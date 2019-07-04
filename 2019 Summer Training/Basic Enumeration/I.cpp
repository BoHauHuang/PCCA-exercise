#include<bits/stdc++.h>
using namespace std;
int n, m;

int f(int *num){
	int fp = 0, p = n;
	
	for(int i = 0 ; i < n ; i ++){
		for(int j = i ; j < n ; j++){
			p = n;
			for(int k = i ; k <= j ; k++){
				if(p > num[k]) p = num[k];
			}
			fp += p;
		}
	}
	
	return fp;
}

int main(){
	cin >> n >> m;
	int num[n];
	for(int i = 1 ; i <= n ; i++)
		num[i-1] = i;
		
	int max = 0;
	
	do{
		if(f(num) > max) max = f(num);
	}while(next_permutation(num, num+n));
	
	for(int i = 1 ; i <= n ; i++)
		num[i-1] = i;
	
	do{
		if(f(num) == max) m--;
		if(m == 0){
			for(int i = 0 ; i < n ; i++)
				cout << num[i] << " ";
			cout << endl;
			break;
		}
	}while(next_permutation(num, num+n));
	
	return 0;
}
