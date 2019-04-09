#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> num;
	int in;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		num.push_back(in);
	}
	
	sort(num.begin(), num.end());
	
	cout << min(num[n-2]-num[0], num[n-1]-num[1]) << endl;
	return 0;
}
