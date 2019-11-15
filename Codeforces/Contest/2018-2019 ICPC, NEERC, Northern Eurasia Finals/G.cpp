#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long T,t,k;
    cin >> T;
    long long a,sum,ans,m,m1;
    long long v[7];
    int i,j;
    while(T--){
        cin >> a;
        sum=0;
        ans=0;
        for(i=0;i<7;i++){
            cin >> v[i];
            if(v[i]==1){
                sum++;
            }
        }
        t=a/sum;
        k=a%sum;
        if(k==0){
            ans=7*(t-1);
            k+=sum;
        }
        else{
            ans=7*t;
        }
        m=7;
        int sum1;
        for(i=0;i<7;i++){
            j=0;
            sum1=k;
            m1=0;
            while(sum1>0){
                if(v[(i+j)%7]==1){
                    m1++;
                    sum1--;
                }
                else{
                    m1++;
                }
                j++;
            }
//           cout << m1 << endl;
            if(m1<m){
                m=m1;
            }
        }
        cout << ans+m << endl;
    }
    return 0;
}
