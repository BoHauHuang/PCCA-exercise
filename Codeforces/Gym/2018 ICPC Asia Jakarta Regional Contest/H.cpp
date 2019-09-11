#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> seq, idx;
map<pair<int,int>,int> s, vis;

int p[MAX * 4], g[MAX * 4];
int ql, qr, n, k, in;

void modify(int x, int y, int now) {
    if (x == y) {
        p[now] = 1;
        return;
    }

    int m = x + (y - x) / 2;
    if (ql <= m) modify(x, m, now * 2);
    if (m  < ql) modify(m + 1, y, now * 2 + 1);

    p[now] = p[now * 2] + p[now * 2 + 1];
}

int query(int x, int y, int now) {
    if (ql <= x && y <= qr) return p[now];

    int m = x + (y - x) / 2, ll = 0, rr = 0;
    if (ql <= m) ll = query(x, m, now * 2);
    if (m  < qr) rr = query(m + 1, y, now * 2 + 1); 

    return ll + rr;
}

void build(int x, int y, int now) {
    if (x == y) {
        p[now] = seq[x];
        return;
    }

    int m = x + (y - x) / 2;
    build(x, m, now * 2);
    build(m + 1, y, now * 2 + 1);

    p[now] = p[now * 2] + p[now * 2 + 1];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    seq.clear();
    memset(p, 0, sizeof(p));
	seq.push_back(0);
	
    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        cin >> in;
        if(in != 0) seq.push_back(in);
        else{
        	seq.push_back(-1);
        	idx.push_back(i+1);
		}
    }
    
    build(1, n, 1);
    
    int a, b, c;
    for(int i = 0 ; i < k ; i++){
        cin >> b >> a >> c;
        if(vis[make_pair(a, b)]) s[make_pair(a, b)] = max(s[make_pair(a, b)], c);
        else{
            vis[make_pair(a, b)] = 1;
            s[make_pair(a, b)] = c;
        }
    }
   
    for(auto x : s){
        qr = x.first.first;
        ql = x.first.second;
        int sum = query(1, n, 1), t = x.second-sum, start = 0;
        
		auto index = upper_bound(idx.begin(), idx.end(), x.first.first);
		if(index == idx.end()) start = idx.size()-1;
		else start = (int)(index-idx.begin())-1;
        
        bool change = false;
    	int final;
    	vector<int> e;

    	for(int i = start ; i >= 0 && idx[i] >= x.first.second ; i--){ 
    		if(t <= 0) break;
    		change = true;
            ql = idx[i];
            modify(1, n, 1);

            seq[idx[i]] = 1;
            t -= 2;
            final = i;
            e.push_back(i);
        }
        
        if(change){
        	for(auto i : e){
        		idx.erase(idx.begin()+i);
			}
		}
	    
        if(t > 0){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; i++)
        cout << seq[i] << " ";
    cout << endl;
    
    return 0;
}
