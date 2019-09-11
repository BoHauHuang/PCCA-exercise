#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, in;
	cin >> n;
	vector<int> color;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		color.push_back(in);
	}
	int front = 0, back = 0;
	for(int i = n-1 ; i >= 1 ; i--){
		if(color[0] != color[i]){
			front = i;
			break;
		}
	}
	for(int i = 0 ; i < n-1 ; i++){
		if(color[n-1] != color[i]){
			back = n-1-i;
			break;
		}
	}
	
	cout << ((front>back)? front:back) << '\n';
	
	return 0;
}
