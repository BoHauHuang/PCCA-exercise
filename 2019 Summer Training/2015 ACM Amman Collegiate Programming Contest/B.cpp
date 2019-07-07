#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
 
int N;
char s[MAX];
int S[MAX], P[MAX], R[MAX];
 
void init() {
	memset(S, 0, sizeof(S));
	memset(P, 0, sizeof(P));
	memset(R, 0, sizeof(R));
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		init();
 
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> s[i];
 
		int win = 0, ans = 0;
		for(int i = 1 ; i <= N ; i++){
			S[i] += ( ((!i)? 0 : S[i-1]) + (s[i] == 'S') );
			P[i] += ( ((!i)? 0 : P[i-1]) + (s[i] == 'P') );
			R[i] += ( ((!i)? 0 : R[i-1]) + (s[i] == 'R') );
		}
		
		for(int i = 0; i <= N ; i++){
			for(int k = 0; i + k <= N ; k++){
				int Rwin = R[i + k] - R[i] - (S[i + k] - S[i]);
				int Pwin = P[N] - P[i + k] - (R[N] - R[i + k]);
				int Swin = S[i] - (P[i]);
 
				if ((Rwin + Pwin + Swin) > 0) ans++;
			}
		}
		cout << ans << endl; 
	}
	
	return 0;
}
