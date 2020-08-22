#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll i,j,n;
    cin >> n;
    string s;
    cin >> s;
    ll a=0,b=0;
    for(i=0;i<n-1;i++){
        if(s[i]==':'&&s[i+1]==')'){
            a++;
        }
        else if(s[i]=='('&&s[i+1]==':'){
            a++;
        }
        else if(s[i]==':'&&s[i+1]=='('){
            b++;
        }
        else if(s[i]==')'&&s[i+1]==':'){
            b++;
        }
    }
    if(a>b){
        cout << "HAPPY" << endl;
    }
    else if(a<b){
        cout << "SAD" << endl;
    }
    else{
        cout << "BORED" << endl;
    }
    return 0;
}
