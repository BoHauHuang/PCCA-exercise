#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int paper[n];
    double l[n], s[n];
    paper[0] = 0;
    
    for(int i = 1 ; i < n ; i++)
        cin >> paper[i];
    
    s[1] = pow(2, -1.25);
    l[1] = pow(2, -0.75);
    
    l[0] = 2.0*s[1];
    s[0] = 0;
    
    for(int i = 2 ; i < n ; i++){
        s[i] = l[i-1]/2;
        l[i] = s[i-1];
    }
    double sum = 0.0;
    int need = 1;
    for(int i = 1 ; i < n ; i++){
        sum += (l[i]*need);
        need *= 2;
        need -= paper[i];
        if(need <= 0){
            cout << fixed;
            cout.precision(11);
            cout << sum << endl;
            return 0;
        }
    }
    
    cout << "impossible" << endl;
    
    return 0;
}
