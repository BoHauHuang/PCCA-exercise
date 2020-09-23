#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string, string> l, pair<string, string> r){
	if(l.first == r.first) return l.second < r.second;
	return l.first > r.first;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	string s[n];
	for(int i = 0 ; i < n ; i++){
		getline(cin, s[i]);
	}
	vector<pair<string, string> > sn;
	for(int i = 0 ; i < n ; i++){
		string nn = "";
		int nid = 0;
		for(int j = 0 ; j < s[i].size() ; j++){
			if(s[i][j] == ':'){
				nid = j;
				break;
			}
			nn += s[i][j];
		}
		bool on = true;
		string qq = "";
		for(int j = nid+2 ; j < s[i].size() ; j++){
			if(on && s[i][j] == 'u'){
				qq += "3";
				on = false;
			}
			else if(on && s[i][j] == 'm'){
				qq += "2";
				on = false;
			}
			else if(on && s[i][j] == 'l'){
				qq += "1";
				on = false;
			}
			else if(!on && s[i][j] == ' '){
				on = true;
			}
			if(on && s[i][j] == 'c') break;
		}
		sn.push_back(make_pair(qq, nn));
	}
	int len = 0;
	for(auto x:sn){
		len=max((int)((x.first).size()), len);
	}

	for(auto &x:sn){
		reverse((x.first).begin(), (x.first).end());
		if((x.first).size() < len){
			int cnt = len-(x.first).size();
			for(int i = 0 ; i < cnt ; i++)
				x.first += "2";
		}
	}
	sort(sn.begin(), sn.end(), cmp);

	for(auto x : sn){
		cout << x.second << '\n';
	}

	return 0;
}