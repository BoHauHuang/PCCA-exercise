#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll n;
    ll i,j,t,k;
    cin >> n;
    map<ll,ll> a;
    for(i=0;i<n;i++){
        cin >> t;
        a[t]++;
    }
    ll ans=0;
    ll sum=0;
    for(auto it:a){
        if(it.first<it.second+sum){
            ans=sum;
            ans+=it.second;
        }
        sum+=it.second;
    }
    cout << ans << endl;
    return 0;
}
