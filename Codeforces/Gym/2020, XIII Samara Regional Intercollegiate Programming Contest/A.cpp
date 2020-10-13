#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin >> n;
    vector<ll> a;
    ll i,j,t,k;
    for(i=0;i<n;i++){
        cin >> t;
        a.push_back(t);
    }
    vector<ll> ans;
    ll sum=0;
    for(i=0;i<a.size();i++){
        if(i%2==0){
            sum+=a[i];
        }
        else{
            sum-=a[i];
        }
    }
    if(n%2==0){
        sum*=-1;
    }
    ll l,r,v;
    cin >> m;
    for(i=0;i<m;i++){
        cin >> l >> r >> v;
        if((r-l+1)%2==1){
            if(l%2==0&&n%2==1){
                sum-=v;
            }
            else if(l%2==1&&n%2==1){
                sum+=v;
            }
            else if(l%2==0&&n%2==0){
                sum+=v;
            }
            else if(l%2==1&&n%2==0){
                sum-=v;
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}
