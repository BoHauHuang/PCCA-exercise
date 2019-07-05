#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> a;
vector<int>::iterator it;

void f(long long n,long long m){
    int i;
    long long n1=1;
    if(n==1){
        a.push_back(1);
    }
    else{
        n1<<=(n-2);
        if(m>n1){
            m=2*(n1)+1-m;
            f(n-1,m);
            reverse(a.begin(),a.end());
            for(i=0;i<a.size();i++){
                a[i]++;
            }
            a.push_back(1);
        }
        else{
            f(n-1,m);
            it=a.begin();
            a.insert(it,1);
            for(i=1;i<a.size();i++){
                a[i]++;
            }
        }
    }

}

int main(){
    long long n,m;
    cin >> n >> m;
    int i;
    f(n,m);
    for(i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
	return 0;
}
