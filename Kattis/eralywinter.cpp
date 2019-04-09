#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, dm, cnt = -1;
	cin >> n >> dm;
	int num[n];
	memset(num, 0, sizeof(num));
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];
	bool valid = false;
	for(int i = 0 ; i < n ; i++){
		cnt = i;
		if(num[i] <= dm){
			valid = true;
			break;
		}
	}
	
	if(!valid) cout << "It had never snowed this early!" << endl;
	else cout << "It hadn't snowed this early in " << cnt << " years!" << endl;
	
	return 0;
}
