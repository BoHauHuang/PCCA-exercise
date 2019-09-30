#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_V 100
#define MAX_E 100000
using namespace std;
int num_v, num_e, start, target;

struct Edge{
	int to, cap, next;
};

Edge edges[MAX_E+5];
int level[MAX_V+5], cur[MAX_V+5], eid;

void add_edge(int from, int to, int capacity){
	edges[eid].to = to;
	edges[eid].cap = capacity;
	edges[eid].next = cur[from];
	cur[from] = eid++;
}

bool bfs_build_level(){
	memset(level, -1, sizeof(level));
	level[start] = 0; 
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = cur[now] ; i != -1 ; i = edges[i].next){
			int next = edges[i].to;
			if(edges[i].cap > 0 && level[next] == -1){
				level[next] = level[now]+1;
				q.push(next);
			}
		}
	}
	return (level[target] != -1);
}

int dfs_find_flow(int now, int r){
	if(now == target) return r;
	
	for(int i = cur[now] ; i != -1 ; i = edges[i].next){
		int here = edges[i].to;
		if(edges[i].cap > 0 && level[here] == level[now]+1){
			int d = dfs_find_flow(here, min(r, edges[i].cap));
			if(d > 0){
				edges[i].cap -= d;
				edges[i^1].cap += d;
				return d;
			}
		}
	}
	level[now] = -1;
	return 0;
}

int dinic(){
	int ans = 0, tmp;
	
	while(bfs_build_level()){
		while((tmp = dfs_find_flow(start, INF)) > 0){
			ans += tmp;
		}
	}
		
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int count = 1;
	while(cin >> num_v && num_v){
		cin >> start >> target >> num_e;
	
		int u, v, c;
		memset(cur, -1, sizeof(cur));
		for(int i = 0 ; i < num_e ; i++){
			cin >> u >> v >> c;
			add_edge(u, v, c);
			add_edge(v, u, c);
		}
		
		cout << "Network " << count++ << '\n' << "The bandwidth is " << dinic() << ".\n\n";
	}
	return 0;
}
