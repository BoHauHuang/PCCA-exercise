struct Edge {
    int from, to, cap, flow;
    Edge(int x, int y, int z, int g):
    from(x), to(y), cap(z), flow(g) {}
};

struct Dicnic {
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
