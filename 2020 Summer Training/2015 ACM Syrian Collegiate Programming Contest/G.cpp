#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,t,k;
    ll n;
    cin >> t;
    string s;
    while(t--){
        cin >> n;
        ll a[n]={0};
        for(i=0;i<3;i++){
            cin >> s;
            for(j=0;j<n*3;j++){
                if(s[j]=='*'){
                    a[j/3]++;
                }
            }
        }
        ll ma=0;
        for(i=0;i<n;i++){
            if(a[i]>ma){
                ma=a[i];
            }
        }
        cout << ma*4 << '\n';
    }
    return 0;
}
