#include<bits/stdc++.h>
using namespace std;
int pre[205], suf[205];

int main(){
	string a, b;
	cin >> a >> b;
	memset(pre, 0, sizeof(pre));
	memset(suf, 0, sizeof(suf));
	
	for(int i = 0, j = 0 ; i < a.size() && j < b.size() ; i++)
		if(a[i] == b[j]) pre[j++] = i;
	
	for(int i = a.size()-1, j = b.size()-1 ; i >= 0 && j >= 0 ; i--)
		if(a[i] == b[j]) suf[j--] = i;
	
	int pre_max = (pre[0] > a.size()-1-pre[b.size()-1])? pre[0] : a.size()-1-pre[b.size()-1];
	int suf_max = (suf[0] > a.size()-1-suf[b.size()-1])? suf[0] : a.size()-1-suf[b.size()-1];
	
	int ans = (pre_max > suf_max)? pre_max : suf_max;
	
	for(int i = 1 ; i < b.size() ; i++)
		if(suf[i]-pre[i-1]-1 > ans) ans = suf[i]-pre[i-1]-1;
	
	cout << ans << endl; 
	
	return 0;	
} 
