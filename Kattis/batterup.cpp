#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, num;
	double sum = 0, cnt = 0;
	cin >> n;
	while(n--){
		cin >> num;
		if(num >= 0){
			sum += num;
			cnt++;
		}
	}
	cout << (double)sum/cnt << endl;
	return 0;
}
