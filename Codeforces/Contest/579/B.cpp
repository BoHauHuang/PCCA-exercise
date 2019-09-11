#include<bits/stdc++.h>
using namespace std;

int main(){
	int q, n;
	cin >> q;
	while(q--){
		cin >> n;
		int a[4*n];
		for(int i = 0 ; i < 4*n ; i++)
			cin >> a[i];
		
		map<int, int> cnt;
		for(int i = 0 ; i < 4*n ; i++)
			cnt[a[i]]++;
		
		bool duo = true;
		for(auto &x : cnt){
			if(x.second % 2) duo = false;
			x.second /= 2;
		}
		
		if(!duo){
			cout << "NO" << endl;
			continue;
		}
		
		vector<int> edge;
		for(auto x : cnt)
			for(int i = 0 ; i < x.second ; i++)
				edge.push_back(x.first);
		
		int area, tmp;
		bool yes = true;
		if(edge.size()%2){
			cout << "NO" << endl;
			yes = false;
			continue;
		}
		for(int i = 0 ; i < edge.size() ; i++){
			if(!i) area = edge[i]*edge[edge.size()-i-1];
			tmp = edge[i]*edge[edge.size()-i-1];;
			if(tmp != area){
				cout << "NO" << endl;
				yes = false;
				break;
			}
		}
		if(yes) cout << "YES" << endl;
		
	}	
	return 0;
}
