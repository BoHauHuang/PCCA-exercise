#include<bits/stdc++.h>
#define MAX 3000
#define INF 0x3f3f3f3f
using namespace std;

map<string, int> name_to_id;

struct Edge {
    int from, to, cap, flow;
    Edge(int x, int y, int z, int g):
    from(x), to(y), cap(z), flow(g) {}
};

struct Dicnic{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> g[MAX];
    bool vis[MAX];
    int d[MAX], cur[MAX];
    
    void init(int n) {
        this -> n = n;
        for (int i = 1; i <= n; i++) g[i].clear();
        edges.clear();
    }
    
    void addedges(int fro, int to, int cap, int flo) {
        edges.push_back((Edge){fro, to, cap, 0});
        edges.push_back((Edge){to, fro, 0, 0});
        m = (int) edges.size();
        g[fro].push_back(m - 2);
        g[to].push_back(m - 1);
    }
    
    bool bfs() {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0; vis[s] = 1;
        
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i < g[now].size(); i++) {
                Edge& e = edges[g[now][i]];
                
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[now] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    
    int dfs(int now, int a) {
        if (now == t || a == 0) return a;
        
        int ans = 0, f = 0;
        for (int& i = cur[now]; i < g[now].size(); i++) {
            Edge& e = edges[g[now][i]];
            
            if (d[now] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[now][i] ^ 1].flow -= f;
                ans += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return ans;
    }
    
    int MaxFlow(int s, int t) {
        this -> s = s;
        this -> t = t;
        
        int ans = 0;
        while (bfs()) {
            memset(cur, 0, sizeof(cur));
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int s, r, f, t;
	cin >> s >> r >> f >> t;
	
	Dicnic solver;
	solver.init(MAX);
	
	string name;
	int name_cnt = 1, startpoint = s+2*t+1, endpoint = s+2*t+2;
	
	for(int i = 0 ; i < r ; i++){
		cin >> name;
		name_to_id[name] = name_cnt++;
		solver.addedges(startpoint, name_to_id[name], 1, 0);
	}
	for(int i = 0 ; i < f ; i++){
		cin >> name;
		name_to_id[name] = name_cnt++;
		solver.addedges(name_to_id[name], endpoint, 1, 0);
	}
	
	int n;
	string start, node;
	for(int i = 1 ; i <= t ; i++){
		cin >> n;
		// one trans
		solver.addedges(s+2*i-1, s+2*i, 1, 0);
		vector<int> ns;
		for(int j = 0 ; j < n ; j++){
			cin >> node;
			if(name_to_id[node] == 0) name_to_id[node] = name_cnt++;
			ns.push_back(name_to_id[node]);
		}
		for(auto v : ns){
			solver.addedges(v, s+2*i-1, 1, 0);
		}
		for(auto v : ns){
			solver.addedges(s+2*i, v, 1, 0);
		}
		
	}
	
	cout << solver.MaxFlow(startpoint, endpoint) << '\n';
}
