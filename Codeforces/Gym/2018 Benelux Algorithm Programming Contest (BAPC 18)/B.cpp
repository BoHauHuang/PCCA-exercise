#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
int m[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d[15][40];
int n, now_day, now_mon, pre_mon, pre_day;
int ans_mon, ans_day, ans_cnt;
 
void init() {
    memset(d, INF, sizeof(d));
    pre_mon = 10;
    pre_day = 26;
    now_mon = 10;
    now_day = 27;
    ans_cnt = 0;
}
 
int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();
 
    int n; cin >> n;
    while (n--) {
        string nam; cin >> nam;
        char c;
        int mon, day;
        cin >> mon >> c >> day;
 
        d[mon][day] = 0;
    }
    int t = 800;
    while (t--) {
        d[now_mon][now_day] = min(d[pre_mon][pre_day] + 1, d[now_mon][now_day]);
 
        pre_mon = now_mon;
        pre_day = now_day;
        now_day += 1;
 
        if (now_day > m[now_mon]) {
            now_day = 1;
            now_mon = now_mon + 1;
 
            if (now_mon == 13) now_mon = 1;
        }
    }
 
    now_day = 28;
    now_mon = 10;
    t = 365;
    while (t--) {
        if (d[now_mon][now_day] > ans_cnt) {
            ans_cnt = d[now_mon][now_day];
            ans_mon = now_mon;
            ans_day = now_day;
        }
 
        now_day += 1;
        if (now_day > m[now_mon]) {
            now_day = 1;
            now_mon = now_mon + 1;
 
            if (now_mon == 13) now_mon = 1;
        }
    }
    cout << setw(2) << setfill('0') << ans_mon;
    cout << '-';
    cout << setw(2) << setfill('0') << ans_day << '\n';
    return 0;
}
