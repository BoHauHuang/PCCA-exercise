#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    Node *ls, *rs;
    char c;
    int siz, flp;
 
    Node(char x) {
        this -> c = x;
        siz = 1;
        flp = 0;
        ls = rs = NULL;
    }
} *rot;
 
int SZ(Node* now) {
    return now == NULL ? 0 : now -> siz;
}
 
void maintain(Node* now) {
    if (now == NULL) return;
    now -> siz = 1 + SZ(now -> ls) + SZ(now -> rs);
    
}
 
void push_down(Node* now) {
    if (now == NULL) return;
    if (now -> flp) {
        now -> flp = 0;
        
        if (now -> ls != NULL) {
            swap(now -> ls -> ls, now -> ls -> rs);
            now -> ls -> flp ^= 1;
        }
        if (now -> rs != NULL) {
            swap(now -> rs -> ls, now -> rs -> rs);
            now -> rs -> flp ^= 1;
        }
    }
}
 
Node* merge(Node* lef, Node* rig) {
    if (lef == NULL) return rig;
    if (rig == NULL) return lef;
 
    if (rand() % (SZ(lef) + SZ(rig)) < SZ(lef)) {
 
        push_down(lef);
        lef -> rs = merge(lef -> rs, rig);
        maintain(lef);
        return lef;
    } else {
 
        push_down(rig);
        rig -> ls = merge(lef, rig -> ls);
        maintain(rig);
        return rig;
    }
}
 
void split(Node* now, int k, Node* &lef, Node* &rig) {
    if (now == NULL) {
        lef = rig = NULL;
        return;
    }
    push_down(now);
 
    if (k <= SZ(now -> ls)) {
        rig = now;
        split(now -> ls, k, lef, rig -> ls);
    } else {
        lef = now;
        split(now -> rs, k - SZ(now -> ls) - 1, lef -> rs, rig);
    }
    maintain(now);
}
 
int n, m, beg, fin;
int ql, qr;
 
void init() {
    rot = NULL;
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();
 
    cin >> n >> beg >> fin;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        rot = merge(rot, new Node(x));
    }
 
    Node *lef, *now, *rig, *tmp;
    cin >> m;
    while (m--) {
        char ope, poi, dir;
        cin >> ope;
        if (ope == 'Q') {
            cin >> poi;
            if (poi == 'L') { qr = beg; ql = beg - 1; }
            if (poi == 'R') { qr = fin; ql = fin - 1; }
 
            split(rot, qr, tmp, rig);
            split(tmp, ql, lef, now);
 
            cout << (char) (now -> c);
 
            rot = merge(merge(lef, now), rig);
        }
        if (ope == 'R') {
            ql = beg - 1; qr = fin;
            split(rot, qr, tmp, rig);
            split(tmp, ql, lef, now);
 
            now -> flp ^= 1;
            swap(now -> ls, now -> rs);
 
            rot = merge(merge(lef, now), rig);
        }
        if (ope == 'S') {
            cin >> poi >> dir;
            if (poi == 'L') beg += (dir == 'L' ? -1 : 1);
            if (poi == 'R') fin += (dir == 'L' ? -1 : 1);
        }
    }
    return 0;
}
