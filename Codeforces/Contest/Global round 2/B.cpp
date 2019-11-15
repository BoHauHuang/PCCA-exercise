#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, h, in, base = 0;
	cin >> n >> h;
	vector<long long> bottle;
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		bottle.push_back(in);
	}
	vector<long long> select;
	for(int i = n ; i >= 1 ; i--){
		for(int j = 0 ; j < i ; j++)
			select.push_back(bottle[j]);
		sort(select.begin(), select.end(), greater<int>());
		long long sum = 0;
		for(int j = 0 ; j < select.size() ; j+=2)
			sum += select[j];
		if(sum <= h){
			cout << i << endl;
			return 0;
		}
		select.clear();
	}
	cout << "0" << endl;
	return 0;
}
