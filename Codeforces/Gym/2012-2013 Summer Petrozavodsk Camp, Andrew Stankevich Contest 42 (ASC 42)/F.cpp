#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
 
    ifstream cin("funny.in");
    ofstream cout("funny.out");
 
 
    bool b[10000]={false};
    vector<long long> p;
    long long i,j;
    i=2;
    while(i<10000){
        if(b[i]==false){
            p.push_back(i);
            b[i]=true;
            j=i;
            while(i+j<10000){
                b[i+j]=true;
                j+=i;
            }
        }
        i++;
    }
/*
    for(i=0;i<p.size();i++){
        cout << p[i] << " ";
    }
    cout <<endl;
*/
    long long w,h,w1,h1;
    long long sum1,sum2;
    while(cin >> w >> h){
        w1=w;
        h1=h;
        sum1=0;
        sum2=0;
        if(w==0&&h==0){
            return 0;
        }
        i=0;
        while(w>1){
            if(w%p[i]==0){
                w/=p[i];
                sum1++;
            }
            else{
                i++;
                if(p[i]*p[i]>w&&w>1){
                    sum1++;
                    break;
                }
            }
        }
        i=0;
        while(h>1){
            if(h%p[i]==0){
                h/=p[i];
                sum2++;
            }
            else{
                i++;
                if(p[i]*p[i]>h&&h>1){
                    sum2++;
                    break;
                }
            }
        }
  //      cout << sum1 << " " << sum2 << endl;
        if(sum1>sum2){
            cout << w1 << " " << h1 << " - Vera" <<'\n';
        }
        else{
            cout << w1 << " " << h1 << " - Harry" <<'\n';
        }
    }
 
    return 0;
}
