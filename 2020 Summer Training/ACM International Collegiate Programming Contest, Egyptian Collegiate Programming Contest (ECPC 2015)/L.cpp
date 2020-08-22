#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll i,j,t,k;
    ll T,n;
    cin >> T;
    while(T--){
        cin >> n;
        vector<ll> a;
        bool ch=false;
        for(i=0;i<n;i++){
            cin >> t;
            a.push_back(t);
        }
        for(i=0;i<a.size();i++){
            k=a[i]%(n*(n-1));
            if(k>=n||k==0){
                ch=true;
                break;
            }
        }
        if(ch){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}
