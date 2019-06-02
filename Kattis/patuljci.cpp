#include<bits/stdc++.h>
using namespace std;

int main(){
	int num[9], sum = 0;
	for(int i = 0 ; i < 9 ; i++){
		cin >> num[i];
		sum += num[i];
	}
	
	int more = sum - 100, a, b;

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(j != i && num[i]+num[j] == more){
				a = i;
				b = j;
				break;
			}
		}
	}
	
	for(int i = 0 ; i < 9 ; i++)
		if(i != a && i != b) cout << num[i] << '\n';
	
	return 0;
}
