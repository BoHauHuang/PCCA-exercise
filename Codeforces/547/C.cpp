#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> q;
	map<int, int> check;
	
	q.push_back(0);
	int in;
	for(int i = 0 ; i < n-1 ; i++){
		cin >> in;
		q.push_back(in);	
	}
	for(int i = 1 ; i < q.size() ; i++)
		q[i] += q[i-1];
	
	int min = q[0];
	for(int i = 1 ; i < q.size() ; i++)
		min = (q[i] < min)? q[i] : min;
	
	int bias = (min <= 0)? -min+1 : 0;
	for(int i = 0 ; i < q.size() ; i++)
		check[q[i]+bias] = 1;
		
	bool has_ans = true;
	for(int i = 1 ; i <= n; i++){
		if(!check[i]){
			has_ans = false;
			break;
		}
	}
	
	if(!has_ans) cout << "-1" << endl;
	else{
		for(int i = 0 ; i < q.size() ; i++)
			cout << q[i]+bias << " "; 
		cout << endl;
	}
	
	
	return 0;
}
