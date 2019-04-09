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
		long long int count = 0;
		vector<int> candy(n+1);
		candy[0] = 0;
		candy[1] = input[0];
		candy[2] = input[1];
		for(int i = 3 ; i <= n ; i++){
			candy[i] = candy[i-2] + input[i-1];
		}
		long long int odd = 0, even = 0;
		for(int i = 1 ; i <= n ; i++){
			odd = 0;
			even = 0;
			if(i%2){ // pick odd
				if(n%2){ // vector length is odd
					long long int change_to_even = candy[n] - candy[i], change_to_odd = candy[n-1] - ((i > 1)? candy[i-1] : 0);
					odd = change_to_odd + ((i > 2)? candy[i-2] : 0);
					even = change_to_even + ((i > 1)? candy[i-1] : 0);
					count += (odd == even);
				}
				else{ // vecotr length is even
					long long int change_to_even = candy[n-1] - candy[i], change_to_odd = candy[n] - ((i > 1)? candy[i-1] : 0);
					odd = change_to_odd + ((i > 2)? candy[i-2] : 0);
					even = change_to_even + ((i > 1)? candy[i-1] : 0);
					count += (odd == even);
				}
			}
			else{ // pick even
				if(n%2){ // vector length is odd
					long long int change_to_even = candy[n] - candy[i-1], change_to_odd = candy[n-1] - candy[i];
					odd = change_to_odd + candy[i-1];
					even = change_to_even + ((i > 2)? candy[i-2] : 0);
					count += (odd == even);
				}
				else{ // vector length is even
					long long int change_to_even = candy[n-1] - ((i > 1)? candy[i-1] : 0), change_to_odd = candy[n] - candy[i];
					odd = change_to_odd + ((i > 1)? candy[i-1] : 0);
					even = change_to_even + ((i > 2)? candy[i-2] : 0);
					count += (odd == even);
				}
			}
		}
		
		cout << count << endl;
	}
	
	return 0;
}
