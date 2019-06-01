#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		int card[n], cnt = 1, pos = 0;;
		memset(card, 0, sizeof(card));
		
		while(cnt <= n){
			int num = 0;
			while(num <= cnt+1){
				if(card[pos] == 0) num++;
				if(num == cnt+1){
					card[pos] = cnt;
					break;
				}
				pos = (pos+1)%n;
			}
			cnt++;
		}
		
		for(int i = 0 ; i < n ; i++)
			cout << card[i] << " ";
		cout << endl;
	}
	
	return 0;
} 
