#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
struct poi {
    int x, y, t;
 
    bool operator<(const poi& rhs) const {
        return t > rhs.t;
    }
};
 
int n, m, d;
char in;
int fx, fy;
 
int main(){
    cin.tie(0), cout.sync_with_stdio(false);
 
    cin >> n >> m >> d;
 
    int map[n + 5][m + 5];
    int vis[n + 5][m + 5];
    int ans[n + 5][m + 5];
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    memset(map, 0, sizeof(map));
    
    priority_queue<poi> monster;
    priority_queue<poi> me;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> in;
            if(in == 'S'){
                map[i][j] = 1;
                me.push({i, j, 0});
            }
            else if(in == 'M'){
                map[i][j] = -1;
                monster.push({i, j, -d});
            }
            else if(in == 'F') {
                fx = i; fy = j;
                map[i][j] = 2;
            }
            else map[i][j] = 0;
        }
    }
 
    int xx[5] = {0, 1, -1, 0, 0};
    int yy[5] = {0, 0, 0, -1, 1};
    int tt = 0;
 
    while(!monster.empty()){
        auto now = monster.top(); monster.pop();
        if (vis[now.x][now.y]) continue;
 
        map[now.x][now.y] = -1;
        vis[now.x][now.y] = 1;
 
        if (now.t == 0) continue;
 
        for (int i = 1; i <= 4; i++) {
            int nx = now.x + xx[i];
            int ny = now.y + yy[i];
 
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
 
            monster.push({nx, ny, now.t + 1});
        }
    }
    
    memset(vis, 0, sizeof(vis));
    if(map[me.top().x][me.top().y] != 1) {
        cout << "-1" << endl;
        return 0;
    }
 
    while(!me.empty()){
        auto now = me.top(); me.pop();
        if (vis[now.x][now.y]) continue;
        if (now.x == fx && now.y == fy) {
            cout << now.t << '\n';
            return 0;
        }
        vis[now.x][now.y] = 1;
        ans[now.x][now.y] = now.t;
 
        for (int i = 1; i <= 4; i++) {
            int nx = now.x + xx[i];
            int ny = now.y + yy[i];
 
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || map[nx][ny] < 0) continue;
 
            me.push({nx, ny, now.t + 1});  
        }
    }
    cout << -1 << '\n';
    return 0;
}
