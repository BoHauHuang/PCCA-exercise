#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	string in;
	cin >> n >> k;
	
	vector<int> step;
	for(int i = 0 ; i < k ; i++){
		cin >> in;
		if(in == "undo"){
			int rev;
			cin >> rev;
			for(int i = 0 ; i < rev ; i++)
				step.pop_back();
		}
		else step.push_back(stoi(in));
	}
	long long sum = 0;
	for(auto x : step)
		sum += x;
		
	if(sum < 0) sum += (ceil(-sum/n)+1)*n;
	
	cout << sum%n << endl;
	
	return 0;
} 
