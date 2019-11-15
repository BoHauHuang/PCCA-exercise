#include<bits/stdc++.h>
using namespace std;

int main(){
	int in;
	vector<int> num;
	for(int i = 0 ; i < 4 ; i++){
		cin >> in;
		num.push_back(in);
	}
	sort(num.begin(), num.end());
	cout << num[3]-num[0] << " " << num[3]-num[1] << " " << num[3]-num[2] << endl;
	 
	return 0;
}
