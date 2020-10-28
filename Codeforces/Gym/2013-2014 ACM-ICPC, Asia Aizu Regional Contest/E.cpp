#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
 
struct sta{
	string s;
	lol cnt;
 
	bool operator < (const sta &rhs) const{
		return cnt > rhs.cnt;
	}
};
 
priority_queue<sta> q;
map<string, bool> vis;
sta target;
 
bool check(sta a, sta b) {
	return a.s == b.s;
}
 
void bfs(sta start, lol ch, lol cv){
	while (!q.empty()) q.pop();
	q.push(start);
 
	while(!q.empty()){
		sta now = q.top(); q.pop();
 		if(vis[now.s] == 1) continue; 
		vis[now.s] = 1;
 
		if (check(now, target)){
			cout << now.cnt << '\n';
			return;
		}
 
		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				if (now.s[i * 3 + j] != '0') continue;
				sta a = now, b = now, c = now, d = now;
 
				a.cnt = now.cnt + ch;
				b.cnt = now.cnt + cv;
				c.cnt = now.cnt + cv;
				d.cnt = now.cnt + ch;
 
				if(i == 0 && j == 0){
					swap(a.s[0], a.s[1]); // left
					swap(b.s[0], b.s[3]); // up
					swap(c.s[0], c.s[6]); // down
					swap(d.s[0], d.s[8]); // right
				}
				else if(i == 0 && j == 1){
					swap(a.s[1], a.s[2]);
					swap(b.s[1], b.s[4]);
					swap(c.s[1], c.s[7]);
					swap(d.s[1], d.s[0]);
				}
				else if(i == 0 && j == 2){
					swap(a.s[2], a.s[3]);
					swap(b.s[2], b.s[5]);
					swap(c.s[2], c.s[8]);
					swap(d.s[2], d.s[1]);
				}
				else if(i == 1 && j == 0){
					swap(a.s[3], a.s[4]);
					swap(b.s[3], b.s[6]);
					swap(c.s[3], c.s[0]);
					swap(d.s[3], d.s[2]);
				}
				else if(i == 1 && j == 1){
					swap(a.s[4], a.s[5]);
					swap(b.s[4], b.s[7]);
					swap(c.s[4], c.s[1]);
					swap(d.s[4], d.s[3]);
				}
				else if(i == 1 && j == 2){
					swap(a.s[5], a.s[6]);
					swap(b.s[5], b.s[8]);
					swap(c.s[5], c.s[2]);
					swap(d.s[5], d.s[4]);
				}
				else if(i == 2 && j == 0){
					swap(a.s[6], a.s[7]);
					swap(b.s[6], b.s[0]);
					swap(c.s[6], c.s[3]);
					swap(d.s[6], d.s[5]);
				}
				else if(i == 2 && j == 1){
					swap(a.s[7], a.s[8]);
					swap(b.s[7], b.s[1]);
					swap(c.s[7], c.s[4]);
					swap(d.s[7], d.s[6]);
				}
				else if(i == 2 && j == 2){
					swap(a.s[8], a.s[0]);
					swap(b.s[8], b.s[2]);
					swap(c.s[8], c.s[5]);
					swap(d.s[8], d.s[7]);
				}
				if (!vis[a.s]) { q.push(a); }
				if (!vis[b.s]) { q.push(b); }
				if (!vis[c.s]) { q.push(c); }
				if (!vis[d.s]) { q.push(d); }
			}
		}
 
	}
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
 
	long long ch, cv;
	while (cin >> ch >> cv) {
		if (ch + cv == 0) break;
		vis.clear();
		
		sta ini;
		string in;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				cin >> in;
				ini.s = ini.s + in;
			}
		}
		target.s = "";
 
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				cin >> in;
				target.s = target.s + in;
			}
		}
		target.cnt = 0;
		ini.cnt = 0;
		bfs(ini, ch, cv);
	}
	return 0;
}
