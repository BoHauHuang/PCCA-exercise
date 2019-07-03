#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char *argv[]){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n,w;
    cin >> n >> w;
    long long i,t;
    vector<long long> a;
    for(i=0;i<2*n;i++){
        cin >> t;
        a.push_back(t);
    }
    stable_sort(a.begin(),a.end());
    long long m1=a[0],m2=a[n];
    long long ans;
    bool ch;
    if(m1*2>m2){
        ans=m2*3*n;
        if(ans%2==0){
            ch=false;
        }
        else{
            ch=true;
        }
        ans/=2;
    }
    else{
        ans=m1*3*n;
    }
    if(ans<w){
        if(ch){
            cout << ans << ".5" << endl;
        }
        else{
            cout << ans <<endl;
        }
    }
    else {
        cout << w << endl;
    }
    return 0;
}
