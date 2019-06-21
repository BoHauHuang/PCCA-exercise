#include<bits/stdc++.h>
using namespace std;

int main(){
	int h, w, n;
	cin >> h >> w >> n;
	int brick[n];
	for(int i = 0 ; i < n ; i++)
		cin >> brick[i];
	
	int pos = 0, complete = 0;
	for(int i = 0 ; i < n ; i++){
		if(pos+brick[i] > w) break;
		else if(pos+brick[i] < w) pos += brick[i];
		else{
			pos = 0;
			complete++;
		}
		if(complete == h) break;
	}
	
	if(complete == h) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
