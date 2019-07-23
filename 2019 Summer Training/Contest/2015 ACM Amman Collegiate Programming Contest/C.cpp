#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		char a[N];
		int s[N], ans = 0;
		for(int i = 0 ; i < N ; i++)
			cin >> a[i];
		
		memset(s, 0, sizeof(s));
		
		for(int i = 0 ; i < N ; i++){
			if(a[i] == '*'){
				s[i-1]++;
				s[i]++;
				s[i+1]++;
			}
		}
		
		for(int i = 0 ; i < N ; i++){
			if(!s[i]){
				ans++;
				s[i+1]++;
				s[i+2]++;
				s[i]++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
