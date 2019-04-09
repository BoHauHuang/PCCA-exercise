#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> rest;
	int in;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		rest.push_back(in);
	}
	int size = rest.size();
	for(int i = 0 ; i < size ; i++){
		rest.push_back(rest[i]);
	}
	int max = 0;
	int len = 0;
	for(int i = 0 ; i < rest.size() ; i++){
		if(rest[i]) len++;
		else{
			max = (max < len)? len:max;
			len = 0;
		}
	}
	cout << max << endl; 
	
	return 0;
}
