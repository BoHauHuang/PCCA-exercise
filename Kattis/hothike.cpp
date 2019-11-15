#include<bits/stdc++.h>
#define INF 50
using namespace std;

int main(){
	int n;
	cin >> n;
	int t[n];
	for(int i = 0 ; i < n ; i++)
		cin >> t[i];
	
	int temp = INF, day = 0;
	
	for(int i = 0 ; i+2 < n ; i++){
		if(max(t[i], t[i+2]) < temp){
			temp = max(t[i], t[i+2]);
			day = i;
		}
	}
	
	cout << day+1 << " " << temp << endl;
	
	return 0;
}
