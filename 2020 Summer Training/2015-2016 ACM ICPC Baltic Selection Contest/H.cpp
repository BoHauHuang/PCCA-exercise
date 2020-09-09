#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    ll i,j,t,k;
    cin >> n >> m;
    ll sum=0;
    k=min(n,m)-1;
    sum=(n+n-k+1)*k/2+(m+m-k+1)*k/2;
    n-=k;
    m-=k;
    t=max(n,m);
    sum+=(t+1);
    cout << sum << '\n';
    return 0;
}
