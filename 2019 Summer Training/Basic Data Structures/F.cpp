#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,s1;
    long long i,t;
    vector<long long> a;
    while(getline(cin,s)){
        a.clear();
        for(i=0;i<s.size();i++){
            if(s[i]!=' '){
                s1+=s[i];
            }
            else{
                t=atoll(s1.c_str());
                if(s1.size()!=0){
                    a.push_back(t);
                }
                s1.clear();
            }
        }
        t=atoll(s1.c_str());
        if(s1.size()!=0){
            a.push_back(t);
        }
        s1.clear();
        vector<long long> ans1,ans2;
        bool ch=true;
        for(i=0;i<a.size();i++){
            if(a[i]<0){
                ans1.push_back(a[i]);
                if(ans2.size()==0){
                    ans2.push_back(a[i]);
                }
                else{
                    t=ans2.back();
                    if(t-a[i]>=0){
                        ch=false;
                        break;
                    }
                    ans2.pop_back();
                    ans2.push_back(t-a[i]);
                    ans2.push_back(a[i]);
                }
            }
            else{
                if(ans1.size()>0&&ans1.back()+a[i]==0){
                    ans1.pop_back();
                }
                else{
                    ch=false;
                    break;
                }
                ans2.pop_back();

            }
        }
        if(ans2.size()!=0){
            ch=false;
        }
        if(ch){
            cout << ":-) Matrioshka!" << '\n';
        }
        else{
            cout << ":-( Try again." << '\n';
        }
    }
	return 0;
}
