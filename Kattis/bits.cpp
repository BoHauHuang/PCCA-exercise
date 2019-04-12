#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, num;
	cin >> n;
	while(n--){
		cin >> num;
		int cnt = 0, max = 0;
		while(num){
			int sub = num;
			while(sub){
				if(sub&1) cnt++;
				sub >>= 1;
			}
			if(cnt > max) max = cnt;
			cnt = 0;
			num /= 10;
		}
		cout << max << endl;
	}
	return 0;
}
