#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, in;
	cin >> n;
	int cnt[43], seq[43], val[6] = {4, 8, 15, 16, 23, 42};
	memset(cnt, 0, sizeof(cnt));
	memset(seq, 0, sizeof(seq));
	
	for(int i = 0 ; i < 6 ; i++)
		seq[val[i]] = i+1;
	
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		bool ok = true;
		for(int j = 0 ; j < seq[in]-1 ; j++){
			if(cnt[in]+1 > cnt[val[j]]){
				ok = false;
				break;
			}
		}
		cnt[in] += ok;
	}
	
	cout << n-cnt[val[5]]*6 << endl;
	
	return 0;
} 
