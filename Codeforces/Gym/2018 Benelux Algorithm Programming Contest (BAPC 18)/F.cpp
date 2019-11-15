#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    map<pair<double,pair<long long,int> >,long long >a;
    map<pair<double,pair<long long,int> >,long long >::iterator it;
    int i;
    long long p,c;
    double t1;
    for(i=0;i<n;i++){
        cin >> p >> c;
        t1=(double)c/p;
        a[make_pair(t1,make_pair(p,i))]=c;
    }
    it=a.begin();
    long long k,k1;
    double t;
    k=m;
    k1=0;
    do{
        k+=it->second;
        k1+=it->first.second.first;
        t=(double)k/k1;
        it++;
        if(it==a.end()) break;
    }while(ceil(t)>it->first.first);
    
    k=ceil(t);
    printf("%lld\n",k);
    return 0;
}
