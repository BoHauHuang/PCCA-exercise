#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc,char *argv[]){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    long long n,l,t;
    cin >> n >> l;
    vector<long long> a;
    int i;
    for(i=0;i<n;i++){
        cin >> t;
        a.push_back(t);
    }
    stable_sort(a.begin(),a.end());
    double ans=0;
    for(i=1;i<a.size();i++){
        if((double)(a[i]-a[i-1])>ans){
            ans=(double)(a[i]-a[i-1]);
        }
    }
    ans/=2;
    double m1,m2;
    m1=a[0]-0;
    m2=l-a[a.size()-1];
    if(ans>=m1&&ans>=m2){
        printf("%.10llf",ans);
    }
    else if(m1>=ans&&m1>=m2){
        printf("%.10llf",m1);
    }
    else{
        printf("%.10llf",m2);
    }
    return 0;
}
