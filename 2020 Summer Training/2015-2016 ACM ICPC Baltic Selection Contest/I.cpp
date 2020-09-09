#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double r,h,R,k;
    cin >> r >> R >> h;
    k=(r*h)/(R-r);
    double ans;
    ans=(r*(k+h))/(sqrt(r*r+k*k)+r);
    if(ans*2<=h){
        cout << fixed << setprecision(12) << ans << endl;
    }
    else{
        cout << fixed << setprecision(12) << h/2 << endl;
    }
    return 0;
}
