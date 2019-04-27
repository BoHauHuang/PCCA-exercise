#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> input;
	for(int i = 0 ; i < n ; i++){
		int c;
		cin >> c;
		input.push_back(c);
	}
	if(n == 1) cout << "1" << endl;
	else{
		long long int count = 0, sum_odd = 0, sum_even = 0;
		for(int i = 1 ; i < n ; i++){
			if(i%2 == 0) sum_even += input[i];
			else sum_odd += input[i];
		}
		if(sum_even == sum_odd) count++;
		
		for(int i = 1 ; i < n ; i++){
			if(i%2 == 0) sum_even += (input[i-1]-input[i]);
			else sum_odd += (input[i-1]-input[i]);
			
			if(sum_odd == sum_even) count++;
		}
		
		cout << count << endl;
	}
	
	return 0;
}
