#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long n;
	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long> > A_take;
	
	long long in, A = 0, B = 0;
	for(long long i = 0 ; i < n ; i++){
		cin >> in;
		A_take.push(in);
		if(i%2){
			B += A_take.top();
			A_take.pop();
		}
	}
	
	while(!A_take.empty()){
		A += A_take.top();
		A_take.pop();
	}
	
	cout << A << " " << B << endl;
	
	return 0;
}
