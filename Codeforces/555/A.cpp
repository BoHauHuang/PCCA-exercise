#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	unordered_set<int> num;
	int cnt = 1;
	num.insert(n);
	while(1){
		n++;
		while(!(n%10)){
			n/=10;
		}
		if(num.count(n) != 0) break;
		num.insert(n);
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
