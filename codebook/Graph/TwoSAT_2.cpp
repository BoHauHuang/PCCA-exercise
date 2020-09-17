struct TwoSAT {
    int n;
    vector<int> g[MAX * 2];
    bool mark[MAX * 2];
    int s[MAX * 2], c;

    bool dfs(int x) {
        if (mark[x ^ 1]) return false;
        if (mark[x]) return true;

        mark[x] = true;
        s[c++] = x;
        for (int i = 0; i < g[x].size(); i++) {
            if (!dfs(g[x][i])) return false;
        }
        return true;
    }

    void init(int n) {
        this -> n = n;
        for (int i = 0; i < n * 2; i++) g[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    // (x = xval) or (y = yval)
    void addclause(int x, int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        g[x ^ 1].push_back(y);
        g[y ^ 1].push_back(x);
    }

    bool solve() {
        for (int i = 0; i < n * 2; i += 2) {
            if (!mark[i] && !mark[i + 1]) {
                c = 0;
                if (!dfs(i)) {
                    while (c > 0) mark[s[--c]] = false;
                    if (!dfs(i + 1)) return false;
                }
            }
        }
        return true;
    }
};
