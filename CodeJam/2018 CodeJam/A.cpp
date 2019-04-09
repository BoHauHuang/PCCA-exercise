#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	int count = 1;
	while(T--){
		int D;
		string s;
		cin >> D >> s;
		bool GG = true;
		
		int cnt = 0;
		int dmg = 0, power = 1, min_power = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == 'S'){
				dmg += power;
				min_power++;
			}
			else power *= 2;
		}
		if(min_power > D) cout << "Case #" << count++ << ": IMPOSSIBLE" << endl;
		else{
			while(dmg > D){
				cnt++;
				for(int i = s.size()-1 ; i > 0 ; i--){
					if(s[i] == 'S' && s[i-1] == 'C'){
						s[i] = 'C';
						s[i-1] = 'S';
						break;
					}
				}	
				dmg = 0;
				power = 1;
				for(int i = 0 ; i < s.size() ; i++){
					if(s[i] == 'S') dmg += power;
					else power *= 2;
				}
				if(dmg <= D) break;
			}
			cout << "Case #" << count++ << ": " << cnt << endl;
		}
	}
	return 0;
}
