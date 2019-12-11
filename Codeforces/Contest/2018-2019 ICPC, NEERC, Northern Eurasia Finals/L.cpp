#include<bits/stdc++.h>
using namespace std;
int n, k;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second > b.second;
	else return a.first < b.first; 
}

int main(){
	cin >> n >> k;
	int a[n], b[n];
	pair<int, int> people[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	
	for(int i = 0 ; i < n ; i++)
		people[i] = make_pair(a[i], b[i]);
	
	sort(people, people+n, cmp);
	
	map<int,int> vis;
	long long ans = 0;
	vector<int> more;
	
	for(int i = 0 ; i < n ; i++){
		if (!vis[people[i].first]) vis[people[i].first] = 1;
		else more.push_back(people[i].second);
	}
	sort(more.begin(), more.end());
	
	int need = k-vis.size();
	for(int i = 0 ; i < need ; i++)
		ans += more[i];
		
	cout << ans << endl;
	 
	return 0;
}

