#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ifstream cin("dragon.in");
	ofstream cout("dragon.out");
 
    long long n,m;
    cin >> n >> m;
    long long n1;
    n1=m;
    long long digit=0;
    while(n1>0){
        digit++;
        n1/=10;
    }
    if(digit>n) cout << "No solution" << endl;
    else{
        cout << m ;
        int i;
        for(i=0;i<n-digit;i++)
            cout << "0";
        cout << endl;
    }
    return 0;
}
