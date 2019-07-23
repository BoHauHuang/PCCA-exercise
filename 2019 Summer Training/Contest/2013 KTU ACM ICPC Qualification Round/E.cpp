#include<bits/stdc++.h>
#define MOD 1013
using namespace std;
 
int main(){
	int T, count = 1;
	cin >> T;
	while(T--){
		int code;
		string s;
		map<long long, long long> res_cnt;
		pair<long long, char> possible[15][MOD+5];
		
		cin >> code >> s;
		
		int mul = 1, unknown = 0;
		res_cnt[0] = 1;
		
		for(int i = s.size()-1 ; i >= 0 ; i--){
			if(s[i] != '?'){
				code -= ((mul*s[i])%MOD);
				if(code < 0) code += MOD;
			}
			else{
				map<long long, long long> tmp;
				
				for(char c = 'a' ; c <= 'z' ; c++){
					for(auto x : res_cnt){
						int val = x.first;
						
						// new value
						val = ((mul*c)%MOD + val)%MOD;
						tmp[val] += x.second;
						
						possible[unknown][val] = make_pair(x.first, c);
					}
				}
				unknown++;
				res_cnt = tmp;
			}
			
			mul *= 31;
			mul %= MOD;
		}
		if(res_cnt[code] != 1) cout << "Case #" << count++ << ": " << res_cnt[code] << endl;
		else{
			for(int i = 0 ; i < s.size() ; i++){
				if(s[i] == '?'){
					unknown--;
					s[i] = possible[unknown][code].second;
					code = possible[unknown][code].first;
				}
				
			}
			cout << "Case #" << count++ << ": " << s << endl;
		}
	}
	
	return 0;
}
