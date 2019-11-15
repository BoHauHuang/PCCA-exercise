#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int i, a = 0, b = 0;
    
    for(i = 0 ; i < s.size() ; i++){
        if(s[i]=='1') a++;
        else b++;
    }
    if(a > b){
    	for(i = 0 ; i < s.size() ; i++)
            cout << 0 ;
	}
    else if(a < b){
    	for(i = 0 ; i < s.size() ; i++)
            cout << 1 ;
	}
    else if(a == b){
        if(s[0] == '1'){
            bool ch = true;
            for(i = 0 ; i < s.size() ; i++){
                if(s[i]=='0') cout << 1 ;
                else if(ch){
                    cout << 0 ;
                    ch=false;
                }
                else cout << 1;
            }
        }
        else{
            bool ch = true;
            for(i = 0 ; i < s.size() ; i++){
                if(s[i]=='1') cout << 0 ;
                else if(ch){
                    cout << 1 ;
                    ch=false;
                }
                else cout << 0;
            }
        }
    }
    return 0;
}
