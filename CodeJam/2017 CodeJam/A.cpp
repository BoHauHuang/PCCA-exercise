#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, K, count = 1, cnt = 0;
	cin >> T;
	string s;
	while(T--){
		cin >> s >> K;
		bool possible = true;
		cnt = 0;
		for(int i = 0 ; i < s.size()-K+1 ; i++){
			if(s[i] == '-'){
				cnt++;
				for(int j = i ; j < i+K ; j++){
					if(s[j] == '+') s[j] = '-';
					else s[j] = '+';
				}
			}
		}
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '-'){
				possible = false;
				break;
			}
		}
		
		if(possible) cout << "Case #" << count++ << ": " << cnt << endl;
		else cout << "Case #" << count++ << ": IMPOSSIBLE" << endl;
	}
	
	return 0;
}
