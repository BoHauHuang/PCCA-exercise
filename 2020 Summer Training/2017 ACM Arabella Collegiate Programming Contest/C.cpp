#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll i,j,t,k,ans1=0,ans2;
        cin >> t;
        for(i=0;i<t;i++){
            cin >> k;
            ans1+=k;
            if(i==0){
                ans2=k;
            }
            else{
                ans2=__gcd(ans2,k);
            }
        }
        cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}
