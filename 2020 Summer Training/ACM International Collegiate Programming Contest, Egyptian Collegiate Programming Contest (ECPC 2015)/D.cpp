#include<bits/stdc++.h>
#define INF 1e7
using namespace std;
vector<long long> res;
vector<pair<int, int> > edge[100010];

void extend_edge(int N){
	for(int i = 1 ; i <= N ; i++){
		int m = INF;
		for(int j = 0 ; j < edge[i].size() ; j++)
			m = min(edge[i][j].second, m);
		for(int j = 0 ; j < edge[i].size() ; j++)
			edge[i][j].second += ((edge[i][j].second-m));
	}
}

void dfs(int now, long long sum){
	for(int i = 0 ; i < edge[now].size() ; i++)
		dfs(edge[now][i].first, sum+edge[now][i].second);
	
	if(edge[now].size() == 0) res.push_back(sum);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		res.clear();
		for(int i = 0 ; i < 100010 ; i++)
			edge[i].clear();
		int N, p, c, Q;
		cin >> N;
		long long qt;
		
		for(int i = 2 ; i <= N ; i++){
			cin >> p >> c;
			edge[p].push_back(make_pair(i, c));
		}
		
		extend_edge(N);
		dfs(1, 0);
		sort(res.begin(), res.end());
		
		cin >> Q;
		while(Q--){
			cin >> qt;
			auto idx = upper_bound(res.begin(), res.end(), qt);
			cout << (idx-res.begin()) << '\n';
		}
		
	}

	return 0;
}

