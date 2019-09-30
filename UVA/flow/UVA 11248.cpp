#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_V 105 
#define MAX_E 20010
using namespace std;
int C;
int num_v, num_e, start, target;

struct Edge{
	int from, to, cap, next, flo;
};

Edge edges[MAX_E], origin[MAX_E];
int vis[MAX_V], level[MAX_V], cur[MAX_V], head[MAX_V], eid = 0, flow = 0, cnt = 1;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

void add_edge(int from, int to, int capacity){
	edges[eid].from = from;
	edges[eid].to = to;
	edges[eid].cap = capacity;
	edges[eid].flo = 0;
	edges[eid].next = head[from];
	head[from] = eid++;
}

bool bfs_build_level(){
	memset(level, -1, sizeof(level));
	memset(vis, 0, sizeof(vis));
	
	level[start] = 0; 
	vis[start] = 1;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = head[now] ; i != -1 ; i = edges[i].next){
			Edge &here = edges[i];
			if(here.cap > here.flo && !vis[here.to]){
				level[here.to] = level[now]+1;
				vis[here.to] = 1;
				q.push(here.to);
			}
		}
	}
	return (vis[target] == 1);
}

int dfs_find_flow(int now, int r){
	if(now == target || r == 0) return r;
	int f, fnow = 0;
	
	for(int &i = cur[now] ; i != -1 ; i = edges[i].next){
		Edge &here = edges[i];
		if(level[here.to] == level[now]+1 && (f = dfs_find_flow(here.to, min(r, here.cap-here.flo))) > 0){
			here.flo += f;
			edges[i^1].flo -= f;
			fnow += f;
			r -= f;
			if(r == 0) break;
		}
	}
	return fnow;
}

int dinic(){
	while(bfs_build_level()){
		memcpy(cur, head, sizeof(head));
		flow += dfs_find_flow(start, INF);
		if(flow >= C) return flow;
	}
		
	return flow;
}

void find_edge(int now_flow){
	vector<pair<int, int> > ans;
	vector<int> check;
	
	for(int j = 0 ; j < 2*num_e; j++)
			origin[j] = edges[j];
			
	for(int i = 0 ; i < num_e*2 ; i += 2)
		if(vis[edges[i].from] && !vis[edges[i].to]) check.push_back(i);

	for(int i = 0 ; i < check.size() ; i++){
		edges[check[i]].cap = edges[check[i]].flo + C;
		int tmp_flow;
		if((tmp_flow = dinic()) >= C) ans.push_back(make_pair(edges[check[i]].from, edges[check[i]].to));
		flow = now_flow;
		for(int j = 0 ; j < 2*num_e ; j++)
			edges[j] = origin[j];
	}
	
	if(ans.empty()) cout << "Case " << cnt++ << ": not possible\n";
	else{
		sort(ans.begin(), ans.end(), cmp);
		
		cout << "Case " << cnt++ << ": possible option:";
		for(int i = 0 ; i < ans.size() ; i++){
			if(i) cout << ",(" << ans[i].first << "," << ans[i].second << ")";
			else cout << "(" << ans[i].first << "," << ans[i].second << ")";
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(cin >> num_v >> num_e >> C){
		if(num_v == 0 && num_e == 0 && C == 0) return 0;
		int u, v, c;
		start = 1;
		target = num_v;
		flow = 0;
		eid = 0;
		
		memset(head, -1, sizeof(head));
		for(int i = 0 ; i < num_e ; i++){
			cin >> u >> v >> c;
			add_edge(u, v, c);
			add_edge(v, u, 0);
		}

		int now_flow = dinic();
		if(now_flow >= C || C == 0) cout << "Case " << cnt++ << ": possible" << '\n';
		else find_edge(now_flow);
	}
}
