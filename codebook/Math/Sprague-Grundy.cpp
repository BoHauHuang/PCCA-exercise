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

/* f[N]: N種可以改變當前狀態的方式 
#define MAX 110
int SG[MAX], State[MAX], f[N];

能開 array 就記所有 SG, ans = SG[x]^SG[y]...^SG[z]
void get_SG() {
    SG[1] = 0;
    for (int i = 2; i <= 30; i++) {
        memset(State, 0, sizeof(State));
        // 標記後繼可能的狀態的SG值 
        for (int j = 0; f[j] <= i && j <= N; j++) State[ SG[i-f[j]] ] = 1;
        // 查詢當前後繼狀態中，SG值中最小的非零值 
        for (int j = 0; ; j++) if (!State[j]) SG[i] = j, break;
        cout << SG[i] << ' ';
    } 
}

開不了array記所有 SG 就找規律, 例如: 
long long SG(long long x) { return x % 2 == 0 ? x / 2: SG(x / 2); }

int main(){
    int t; cin >> t;
    while (t--) {
        int n;
        long long a, v = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a, v ^= SG(a);
        cout << (v ? "YES" : "NO") << '\n';
    }
    return 0; } */