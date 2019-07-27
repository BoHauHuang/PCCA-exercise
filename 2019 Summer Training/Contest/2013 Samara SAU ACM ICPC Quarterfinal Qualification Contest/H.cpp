#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	string a, b, tmp;
	vector<string> ans;
	cin >> n >> a >> b;

	tmp.clear();
	for(int i = 0 ; i < n ; i++){
		if(a[i] != b[i]) tmp += a[i];
		else{
			if(tmp.size()){
				ans.push_back(tmp);
				tmp.clear();
			} 
		}
	}
	
	if(tmp.size()) ans.push_back(tmp);
	
	cout << ans.size() << endl;
	
	return 0;
}
