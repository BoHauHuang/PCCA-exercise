#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, in;
	cin >> n;
	vector<int> num;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		num.push_back(in);
	}
	int max = 0, min = 100;
	for(int i = 0 ; i < n ; i++){
		if(num[i] > max) max = num[i];
		if(num[i] < min) min = num[i];
	}
	vector<int> origin;
	origin = num;
	int bias_2 = (max-min)/2, bias = max-min;
	int target_2 = max-bias_2, target = max-bias;
	bool is_double_bias = true, is_one_bias = true;
	for(int i = 0 ; i < n ; i++){
		if(num[i] < target_2) num[i] += bias_2;
		if(num[i] > target_2) num[i] -= bias_2;
		if(num[i] != target_2){
			is_double_bias = false;
			break;
		}
	}
	num = origin;
	for(int i = 0 ; i < n ; i++){
		if(num[i] < target) num[i] += bias;
		if(num[i] > target) num[i] -= bias;
		if(num[i] != target){
			is_one_bias = false;
			break;
		}
	}
	
	if(is_double_bias && is_one_bias) cout << ((bias_2 > bias)? bias : bias_2) << endl;
	else if(is_double_bias) cout << bias_2 << endl;
	else if(is_one_bias) cout << bias << endl;
	else cout << "-1" << endl;
	
	return 0;
}
