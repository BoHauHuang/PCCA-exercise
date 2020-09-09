#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        double c=0,a=1,ans=0,m;
        while(next_permutation(s.begin(),s.end())){
            c++;
        }
        for(i=1;i<=s.size();i++){
            a*=i;
        }
        double k1,k2;
        k1=c-1;
        k2=1;
        m=1;
        //cout << c << " " << a <<  endl;
        if(c==0){
            ans=0;
        }
        else{
            ans=(1/a)*pow(1+1/a,c-1);
        }
        cout << fixed << setprecision(9) << ans << endl;
    }
    return 0;
}

