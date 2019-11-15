#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_V 105 
#define MAX_E 20010
using namespace std;
int num_v, num_e, start, target;

struct Edge{
	int from, to, cap, flo, next;
};

Edge edges[MAX_E], origin[MAX_E];
int vis[MAX_V], level[MAX_V], cur[MAX_V], head[MAX_V], eid = 0, flow = 0;

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
	}
		
	return flow;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(cin >> num_v >> num_e){
		if(num_v == 0 && num_e == 0) return 0;
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
	}
}
