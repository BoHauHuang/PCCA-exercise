#include <bits/stdc++.h>
using namespace std;
 
map<int, int> mp;
int num, dif = 0;
int mot;
 
void init() {
    mp.clear();
    num = 0;
    mot = 0;
}
 
void add(int x) {
    if (mp[x] == 0) {
        num += 1;
    }
    mp[x] += 1;
    if (mp[x] == 2) mot += 1;
}
 
void del(int x) {
    if (mp[x] == 0) return;
    if (mp[x] == 1) {
        num --;
    }
    mp[x] -= 1;
    if (mp[x] == 1) mot -= 1;
}
 
int main() {
    ifstream cin ("homo.in");
    ofstream cout("homo.out");
    init();
 
    int t; cin >> t;
    while (t--) {
        string ope; int x;
        cin >> ope >> x;
 
        if (ope == "insert") add(x);
        if (ope == "delete") del(x);
 
        if (mot && num >= 2) cout << "both\n";
        else if (mot) cout << "homo\n";
        else if (num >= 2) cout << "hetero\n";
        else
            cout << "neither\n";
    }
 
    return 0;
}
