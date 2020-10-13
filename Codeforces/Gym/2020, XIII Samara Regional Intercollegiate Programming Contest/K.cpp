#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    vector<ll> a;
    ll i,n;
    for(i=0;i<4;i++){
        cin >> n;
        a.push_back(n);
    }
    stable_sort(a.begin(),a.end());
    if(a[0]+a[3]==a[1]+a[2]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }    
}
