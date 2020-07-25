#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll a,b,n,y;
        cin >> a >> b >> n;
        ll i,j,t,k;
        y=a+b;
        i=1;
        ll d1[10]={0};
        ll ans[10]={0};
        if(y>n){
            cout << -1 << '\n';
        }
        else{
            while(y<=n){
                for(j=0;j<10;j++){
                    d1[j]=0;
                }
                while(y>0){
                    d1[y%10]++;
                    y/=10;
                }
                ll m=-1;
                for(j=0;j<10;j++){
                    if(d1[j]>m){
                        m=d1[j];
                    }
                }
                for(j=0;j<10;j++){
                    if(d1[j]==m){
                        ans[j]++;
                    }
                }
                i++;
                y=a*i*i+b*i;
                //for(j=0;j<10;j++){
                //    cout << ans[j] << " " ;
                //}
                //cout << endl;
                //cout << y << "  1111" << endl;
            }
            ll ma=0;
            for(j=0;j<10;j++){
                if(ans[j]>ma){
                    ma=ans[j];
                }
            }
            for(j=0;j<10;j++){
                if(ans[j]==ma){
                    cout << j << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
