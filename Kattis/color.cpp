#include<bits/stdc++.h>
using namespace std;

int main(){
	int S, C, K;
	cin >> S >> C >> K;
	vector<int> sock;
	int in;
	for(int i = 0 ; i < S ; i++){
		cin >> in;
		sock.push_back(in);
	}
	sort(sock.begin(), sock.end());
	
	vector<vector<int> > ans;
	vector<int> tmp;
	for(int i = 0 ; i < S ; i++){
		if(tmp.size() == 0) tmp.push_back(sock[i]);
		else{
			if((sock[i] - tmp[0]) <= K) tmp.push_back(sock[i]);
			else{
				ans.push_back(tmp);
				tmp.clear();
				tmp.push_back(sock[i]);
			}
		}
		if(tmp.size() == C){
			ans.push_back(tmp);
			tmp.clear();
		}
	}
	if(tmp.size() > 0) ans.push_back(tmp);
	
	cout << ans.size() << endl;
	
	return 0;
}
