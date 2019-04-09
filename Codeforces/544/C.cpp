#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> p;
	int in;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		p.push_back(in);
	}
	sort(p.begin(), p.end());
	int max = 1;
	for(int i = 0, j = 1 ; i < n && j < n ; ){
		if(p[j]-p[i] <= 5){
			max = (max < j-i+1)? j-i+1 : max;
			j++;
		}
		else i++;
	}
	cout << max << endl;
	return 0;
}
