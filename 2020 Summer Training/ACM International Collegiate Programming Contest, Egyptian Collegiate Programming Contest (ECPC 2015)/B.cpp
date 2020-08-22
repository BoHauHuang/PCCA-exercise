#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll i,j,t,k;
    ll T;
    cin >> T;
    while(T--){
        cin >> t >> k;
        vector<char> ans;
        set<char> b[t];
        char c,a;
        for(i=0;i<t;i++){
            ans.push_back('?');
        }
        for(i=0;i<k;i++){
            for(j=0;j<t;j++){
                cin >> c >> a;
                if(a=='T'){
                    ans[j]=c;
                }
                else{
                    b[j].insert(c);
                }
            }
        }
        for(i=0;i<ans.size();i++){
            if(b[i].size()<3){
                cout << ans[i] ;
            }
            else if(b[i].size()==3){
                if(b[i].find('A')==b[i].end()){
                    cout << 'A' ;
                }
                else if(b[i].find('B')==b[i].end()){
                    cout << 'B' ;
                }
                else if(b[i].find('C')==b[i].end()){
                    cout << 'C' ;
                }
                else if(b[i].find('D')==b[i].end()){
                    cout << 'D' ;
                }
            }
            if(i!=ans.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
