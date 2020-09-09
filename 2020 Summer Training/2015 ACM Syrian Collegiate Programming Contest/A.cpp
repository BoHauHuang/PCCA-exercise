#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,t,k;
    ll n,sum,u;
    cin >> t;
    char c;
    while(t--){
        cin >> n;
        sum=0;
        u=((ll)1<<50);
        for(i=0;i<n;i++){
            cin >> k >> c;
            if(c=='+'){
                sum+=(k+25);
            }
            else{
                u=min(u,sum+k+25);
            }
        }
        cout << u-sum << '\n';
    }
    return 0;
}
 
