#include <bits/stdc++.h>
using namespace std;
 
map<char, string> mp;
 
int main() {
	mp.clear();
	mp['a'] = "as";
	mp['i'] = "ios";
	mp['y'] = "ios";
	mp['l'] = "les";
	mp['n'] = "anes";
	mp['o']  = "os";
	mp['r'] = "res";
	mp['t'] = "tas";
	mp['u'] = "us";
	mp['v'] = "ves";
	mp['w'] = "was";
 
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
 
		int n = (int) s.length();
		if (s[n - 2] == 'n' && s[n - 1] == 'e') {
			for (int i = 0; i < n - 2; i++) cout << s[i];
			cout << "anes\n";
			continue;
		}
 
		for (int i = 0; i < s.length() - 1; i++) cout << s[i];
 
		for (int i = s.length() - 1; i < s.length(); i++) {
			if (s[i] == 'a') { cout << mp[s[i]]; continue; }
			if (s[i] == 'i') { cout << mp[s[i]]; continue; }
			if (s[i] == 'y') { cout << mp[s[i]]; continue; }
			if (s[i] == 'l') { cout << mp[s[i]]; continue; }
			if (s[i] == 'n') { cout << mp[s[i]]; continue; }
			if (s[i] == 'o') { cout << mp[s[i]]; continue; }
			if (s[i] == 'r') { cout << mp[s[i]]; continue; }
			if (s[i] == 't') { cout << mp[s[i]]; continue; }
			if (s[i] == 'u') { cout << mp[s[i]]; continue; }
			if (s[i] == 'v') { cout << mp[s[i]]; continue; }
			if (s[i] == 'w') { cout << mp[s[i]]; continue; }
 
			if (i == s.length() - 1) {
				cout << s[n - 1] << "us";
				continue;
			}
		}
		cout << '\n';
	}
 
	return 0;
}
