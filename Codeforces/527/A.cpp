#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int len[n], kind[n];
	for(int i = 0 ; i < n ; i++)
		cin >> len[i] >> kind[i];
		
	for(int i = 0 ; i < n ; i++){
		int min_f = floor(len[i]/kind[i]);
		int total = len[i];
		int nums[kind[i]] = {0};
		
		for(int j = 0 ; j < kind[i] ; j++){
			nums[j] = (j == kind[i]-1)? total : min_f;
			total = (total >= min_f)? total-min_f : 0;
		}
		for(int j = 0 ; j < kind[i] ; j++){
			for(int k = 0 ; k < nums[j] ; k++){
				cout << (char)(j+'a');
			}
		}
		cout << endl;
	}
	return 0;
} 
