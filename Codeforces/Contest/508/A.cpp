#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	string s;
	
	cin >> n >> k >> s;
	
	int cnt[26], ans = 100010;
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0 ; i < s.size() ; i++)
		cnt[(int)s[i]-'A']++;
	
	for(int i = 0 ; i < k ; i++){
		if(cnt[i] != 0) ans = (ans < cnt[i])? ans : cnt[i];
		else{
			ans = 100010;
			break;
		}
	}
		
	if(ans != 100010) cout << ans*k << endl;
	else cout << "0" << endl;

	return 0;
}

