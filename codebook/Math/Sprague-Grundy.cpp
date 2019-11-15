#include<bits/stdc++.h>
using namespace std;
 
int mex(set S) {
  // find the min number >= 0 that not in the S
  // e.g. S = {0, 1, 3, 4} mex(S) = 2
}

state = []
int SG(A) {
  if (A not in state) {
    S = sub_states(A)
    if( len(S) > 1 ) state[A] = reduce(operator.xor, [SG(B) for B in S])
    else state[A] = mex(set(SG(B) for B in next_states(A)))
  }
  return state[A]
}

// ~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
using namespace std;

#define MAX 110
int sg[MAX], vis[MAX];

int main() {
    sg[1] = 0;
    for (int i = 2; i <= 30; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j * 2 <= i; j++) vis[sg[i - j]] = 1;
        for (int j = 0; ; j++) if (!vis[j]) {
            sg[i] = j;
            break;
        }
        cout << sg[i] << ' ';
    }
    return 0;
}
 
long long SG(long long x) {
    return x % 2 == 0 ? x / 2: SG(x / 2);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; 
        long long a, v = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v ^= SG(a);
        }
        cout << (v ? "YES" : "NO") << '\n';
    }
    return 0;
}
