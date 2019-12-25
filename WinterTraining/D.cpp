#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt[26], one = 0, zero = 0;
	string s;
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> s;
	
	for(int i = 0 ; i < n ; i++)
		cnt[(int)s[i]-'a']++;
	
	one += min(cnt[(int)'o'-'a'], min(cnt[(int)'n'-'a'], cnt[(int)'e'-'a']));
	
	cnt[(int)'o'-'a'] -= one;
	cnt[(int)'n'-'a'] -= one;
	cnt[(int)'e'-'a'] -= one;

	zero += min(cnt[(int)'z'-'a'], min(cnt[(int)'e'-'a'], min(cnt[(int)'r'-'a'], cnt[(int)'o'-'a'])));
	
	for(int i = 0 ; i < one ; i++)
		cout << "1" << " ";
	for(int i = 0 ; i < zero ; i++)
		cout << "0" << " ";
	
	return 0;
}
