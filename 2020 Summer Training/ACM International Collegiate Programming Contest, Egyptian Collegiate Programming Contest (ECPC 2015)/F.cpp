#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll t;
    cin >> t;
    ll w,h;
    while(t--){
        cin >> w >> h;
        if(w==h){
            cout << "Square" << endl;
        }
        else{
            cout << "Rectangle" << endl;
        }
    }
    return 0;
}

