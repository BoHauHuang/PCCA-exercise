#include<bits/stdc++.h>
using namespace std;

int main(){
	string N, M;
	cin >> N >> M;
	int cnt = (M.size()-1 >= 0)? M.size()-1 : 0;
	vector<char> num;
	if(M == "1") cout << N << endl;
	else{
		if(N.size() > cnt){
			int idx = N.size()-cnt;
			for(int i = 0 ; i < N.size() ; i++){
				if(idx == i) num.push_back('.');
				num.push_back(N[i]);
			}
			for(int i = num.size()-1 ; i >= 0 ; i--){
				if((num[i] >= '1' && num[i] <= '9') || num[i] == '.') break;
				num.pop_back();
			}
			for(int i = 0 ; i < num.size() ; i++){
				if(i == num.size()-1 && num[i] == '.') break;
				cout << num[i];
			}
			cout << endl;
		}
		else{
			int lead = cnt-N.size()+1;
			vector<char> num;
			for(int i = 0 ; i < lead ; i++){
				cout << "0";
				if(i == 0) cout << ".";
			}
			for(int i = 0 ; i < N.size() ; i++)
				num.push_back(N[i]);
			for(int i = num.size()-1 ; i >= 0 ; i--){
				if(num[i] >= '1' && num[i] <= '9') break;
				num.pop_back();
			}
			for(int i = 0 ; i < num.size() ; i++)
				cout << num[i];
			cout << endl;
		}
	}
	
	return 0;
}
