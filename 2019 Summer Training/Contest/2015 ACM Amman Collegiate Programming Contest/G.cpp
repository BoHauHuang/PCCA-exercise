#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T,t;
    cin >> T;
    int n,s,i,j;
    while(T--){
        vector<int> a;
        cin >> n >> s;
        for(i=0;i<n;i++){
            cin >> t;
            a.push_back(t);
        }
        int c=0;
        int b;
        int m,sum,ans=0;
        for(i=1;i<pow(2,n);i++){
            j=0;
            b=i;
            m=100000;
            sum=0;
            c=0;
            while(b>0){
                if(b%2==1){
                    sum+=a[j];
                    c++;
                    if(a[j]<m){
                        m=a[j];
                    }
                }
                j++;
                b/=2;
            }
            if(sum>=s&&sum-s<m){
                if(c>ans){
                    ans=c;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
