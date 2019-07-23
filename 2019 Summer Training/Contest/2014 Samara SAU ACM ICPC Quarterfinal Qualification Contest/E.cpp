#include<bits/stdc++.h>
using namespace std;
 
int main(){
	string in;
	cin >> in;
	int cnt[27];
	memset(cnt, 0 , sizeof(cnt));
	
	for(int i = 0 ; i < in.size() ; i++)
		cnt[in[i]-'a']++;
	
	bool valid = true;
	for(int i = 0 ; i < 27 ; i++){
		if(cnt[i] > in.size()/2){
			valid = false;
			break;
		}
	}
	
	cout << ((valid && in.size()%2 == 0)? "YES" : "NO") << endl;
	
	return 0;
}
