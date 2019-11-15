#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define MAX 80
#define F first
#define S second
 
int xx[5] = {0, 1, 0, -1, 0};
int yy[5] = {0, 0, 1, 0, -1};
vector<pii> ans;
 
void init() {
    ans.clear();
}
 
int main() {
    init();
 
    int n; cin >> n;
    ans.push_back(make_pair(1, 1));
    n -= 1;
 
    int now_x = 1, now_y = 1, dir = 1;
    for (int i = 1; n - 2 >= 0; i++) {
        if (now_y == 7) break;
        else if (now_x == 8 && now_y % 2 == 0) dir = 3;
        else if (now_x == 1 && now_y % 2 == 1) dir = 1;
        else if (now_x == 8 && dir == 1) dir = 2;
        else if (now_x == 1 && dir == 3) dir = 2;
 
        now_x += xx[dir];
        now_y += yy[dir];
 
        ans.push_back(make_pair(now_x, now_y));
        n --;
    }
    if (now_y == 7) {
        if (n == 1) {
            ans.push_back(make_pair(1, 8));
 
        } else {
            for (int i = 8; i >= 2 && n; i--) {
                ans.push_back(make_pair(i, 7));   
                n --;
 
                if (n == 1) {
                    if (i == 8) {
                        ans.pop_back();
                        ans.push_back(make_pair(2, 7));
                        i = 2;
                    }
                    ans.push_back(make_pair(i, 8));
                    n --;
                }
            }
            if (n) {
                ans.push_back(make_pair(2, 8));
                n --;
                if (n) {
                    ans.push_back(make_pair(1, 8));
                    n --;
                }
                for (int i = 3; i <= 7 && n; i++) {
                    ans.push_back(make_pair(i, 8));
                    n --;
                }
            }
        }
    }
    else if (now_y <= 6) {
        if (now_x == 8) ans.push_back(make_pair(8, 7));
        else {
            ans.push_back(make_pair(now_x, 8));
        }
    }
 
 
    ans.push_back(make_pair(8, 8));
    for (auto i : ans) {
        cout << (char)(i.S + 'a' - 1) << i.F << ' ';
    }
 
    return 0;
}

