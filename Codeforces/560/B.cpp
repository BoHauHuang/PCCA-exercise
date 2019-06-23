#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int in;
	map<int, int> cnt;
	for(int i = 0 ; i< n ; i++){
		cin >> in;
		cnt[in]++;
	}
	
	int ans = 1;
	map<int, int>::iterator it = cnt.begin();
	while(it != cnt.end()){
		if(it->first >= ans && it->second > 0){
			ans++;
			it->second--;
		}
		else it++;
	}
	
	cout << ans-1 << endl;
	
	return 0;
}
