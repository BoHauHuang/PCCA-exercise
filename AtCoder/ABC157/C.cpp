#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int s[M], c[M], num[N];
	
	for(int i = 0 ; i < N ; i++)
		num[i] = -1;
	
	bool ans = true;
	for(int i = 0 ; i < M ; i++){
		cin >> s[i] >> c[i];
		if(num[s[i]-1] == -1) num[s[i]-1] = c[i];
		else{
			if(num[s[i]-1] != c[i]){
				ans = false;
				break;
			}
		}
	}
	
	if(ans){
		if(num[0] == 0 && N > 1) cout << "-1" << endl;
		else{
			for(int i = 0 ; i < N ; i++)
				if(num[i] == -1) num[i] = 0;
				
			if(num[0] == 0 && N > 1) num[0] = 1;
			
			for(int i = 0 ; i < N ; i++)
				cout << num[i];
		}
	}
	else cout << "-1" << endl;

	return 0;
}
