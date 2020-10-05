#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<ll> a[105];
 
int main(){
    ll i,j,k1,k2;
    ll n,m,s,t;
    cin >> n >> m >> s >> t;
    for(i=0;i<m;i++){
        cin >> k1 >> k2;
        a[k1].push_back(k2);
        a[k2].push_back(k1);
    }
    ll ans1[n]={0},ans2[n]={0};
    ans1[s]=1;
    while(t--){
        for(i=0;i<n;i++){
            for(j=0;j<a[i].size();j++){
                ans2[a[i][j]]+=ans1[i];
            }
        }
        for(i=0;i<n;i++){
            ans1[i]=ans2[i];
            ans2[i]=0;
        }
    }
    ll sum=0;
    for(i=0;i<n;i++){
        sum+=ans1[i];
    }
    cout << sum << endl;
    return 0;
}
