#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll a,b,c,d,e,f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    ll sum=0;
    if(d>a){
        sum+=(d-a);
    }
    if(e>b){
        sum+=(e-b);
    }
    if(f>c){
        sum+=(f-c);
    }
    cout << sum << endl;
    return 0;
}
