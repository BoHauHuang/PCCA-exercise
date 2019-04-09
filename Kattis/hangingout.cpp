#include<bits/stdc++.h>
using namespace std;

int main(){
	int L, x, in, sum = 0, cnt = 0;
	string state;
	
	cin >> L >> x;
	while(x--){
		cin >> state >> in;
		if(state == "enter" && sum + in > L) cnt++;
		else if(state == "enter" && sum + in <= L) sum += in;
		else if(state == "leave") sum = (sum-in > 0)? sum-in : 0;
	}
	cout << cnt << endl;
	
	return 0;
}
