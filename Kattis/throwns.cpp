#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, ans = 0;
	cin >> n >> k;
	string in;
	vector<int> q;
	for(int i = 0 ; i < k ; i++){
		cin >> in;
		if(in == "undo"){
			int m;
			cin >> m;
			while(m--) q.pop_back();
		}
		else q.push_back(stoi(in));
	}
	
	for(int i = 0 ; i < q.size() ; i++)
		ans=(ans+q[i])%n;
	
	if(ans < 0) ans += n;
	cout << ans << endl;
	
	return 0;
}
