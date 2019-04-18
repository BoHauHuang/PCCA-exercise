#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		bool free = true;
		int one = 0, zero = 0;
		for(int i = 0 ; i < s.size() ; i++){
			int ascii = s[i], cnt = 0;
			while(ascii){
				if(ascii&1) one = !one;
				else zero = !zero;
				cnt++;
				ascii >>= 1;
			}
			while(cnt < 7){
				zero = !zero;
				cnt++;
			}
		}
		free = !one & !zero;
		if(free) cout << "free" << endl;
		else cout << "trapped" << endl;
	}
	
	return 0;
}
