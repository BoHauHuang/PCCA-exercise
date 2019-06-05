#include<bits/stdc++.h>
using namespace std;

int main(){
	int P, K, N;
	cin >> P;
	while(P--){
		cin >> K >> N;
		int in;
		vector<int> num;
		
		for(int i = 0 ; i < N ; i++){
			cin >> in;
			num.push_back(in);
		}
		
		int idx = 0;
		vector<int> tmp = num;
		sort(tmp.begin(), tmp.end());
		
		for(int i = 0 ; i < N ; i++)
			if(num[i] == tmp[idx]) idx++;
		
		cout << K << " " << N-idx << endl; 
	}
	
	return 0;
}
