typedef long long lol;
#define MAX 100010

struct Edge {
    int x, y;
    lol c;
    bool operator < (const Edge& rhs) const {
        return c < rhs.c;
    }
};

vector<Edge> v, g;
int p[MAX], s[MAX], n, m;
lol b[MAX], ans_min, ans_smi;

void init() {
    memset(b, 0, sizeof(b));
    for (int i = 1; i < MAX; i++) {
        p[i] = i;
        s[i] = 1;
    }
    ans_min = 0;
    ans_smi = 10000000000000000;
    v.clear();
    g.clear();
}

int findset(int x) {
    return p[x] == x ? x : findset(p[x]);
}

void unio(int x, int y, lol c) {
    if (s[x] > s[y]) {
        p[y] = x;
        s[x] += s[y];
        b[y] = c;
    } else {
        p[x] = y;
        s[y] += s[x];
        b[x] = c;
    }
}

lol find(int x, int y) {
    lol now = 0;
    while (x != y) {
        if (s[x] < s[y]) {
            now = max(now, b[x]);
            x = p[x];
        } else {
            now = max(now, b[y]);
            y = p[y];
        }
    }
    return now;
}

void solve() {
    for (int i = 0; i < m; i++) {
        Edge e = v[i];
        int x = findset(e.x), y = findset(e.y);
        if (x == y) g.push_back(e);
        else {
            ans_min += e.c;
            unio(x, y, e.c);
        }
    }
    for (int i = 0; i < g.size(); i++) {
        Edge e = g[i];
        int x = e.x, y = e.y;
        lol now = find(x, y);
        ans_smi = min(ans_smi, e.c - now);
    }
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; lol c;
        cin >> x >> y >> c;
        v.push_back((Edge){x, y, c});
    }
    sort(v.begin(), v.end());
    solve();
    cout << ans_min << ' ' << ans_smi + ans_min << '\n';
    return 0;
}
