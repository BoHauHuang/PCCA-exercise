#include<bits/stdc++.h>
using namespace std;

bool cmp(string lhs, string rhs){
	string left, right;
	for(int i = 0 ; i < lhs.size() ; i++){
		if(lhs[i] >= 'a' && lhs[i] <= 'z') left += lhs[i];
		else left += ((char)lhs[i]-'A'+'a');
		
		if(rhs[i] >= 'a' && rhs[i] <= 'z') right += rhs[i];
		else right += ((char)rhs[i]-'A'+'a'); 
	}
	
	return (right > left);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, c, cnt = 0;
	while(cin >> r >> c){
		if(!r && !c) break;
		
		char word[r][c];
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				cin >> word[i][j];
			}
		}
		vector<string> ans;
		for(int j = 0 ; j < c ; j++){
			string tmp;
			for(int i = 0 ; i < r ; i++){
				tmp += word[i][j];
			}
			ans.push_back(tmp);
			tmp.clear();
		}
		sort(ans.begin(), ans.end(), cmp);
		
		if(cnt) cout << '\n';
		cnt++;
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < ans.size() ; j++){
				cout << ans[j][i];
			}
			cout << '\n';
		}
	}
	return 0;
}
