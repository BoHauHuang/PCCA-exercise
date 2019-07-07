#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main(){
    int T,t;
    int i,j,k;
    cin >> T;
    string s,s1;
    while(T--){
        cin >> s;
        k=s.size();
        k--;
        while(k>0){
            s1=s;
            for(i=0;i<s1.size()-k;i++){
                t=s1[i]-s1[i+1];
                for(j=1;j<=k;j++){
                    s1[i+j]+=t;
                    if(s1[i+j]>'9'){
                        s1[i+j]-=10;
                    }
                    else if(s1[i+j]<'0'){
                        s1[i+j]+=10;
                    }
                }
            }
            
            int sum1=0,sum2=0;
            char c1,c2;
            c1=s1[0];
            bool ch1=false;
            for(i=0;i<s1.size();i++){
                if(s1[i]==c1){
                    sum1++;
                    if(i==s1.size()-1){
                        ch1=true;
                    }
                }
                else{
                    break;
                }
            }
            c2=s1[i];
            bool ch=true;
            for(;i<s1.size();i++){
                if(s1[i]!=c2){
                    ch=false;
                }
            }
            if(ch1){
                cout << k << endl;
                break;
            }
            else{
                if(ch&&sum1%k==0){
                    cout << k << endl;
                    break;
                }
                else{
                    k--;
                }
            }
        }
    }
    return 0;
}
 
