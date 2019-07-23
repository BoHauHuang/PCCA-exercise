#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ans;

void post_order(string s1,string s2){
//    cout << s1 << " " << s2 << endl;
    if(s1.size()==1&&s2.size()==1){
        ans=ans+s1;
    }
    else if(s1.size()!=0&&s2.size()!=0){
        int i;
        char c;
        c=s1[0];
        ans=ans+c;
        for(i=0;i<s2.size();i++){
            if(s2[i]==c){
                break;
            }
        }
        post_order(s1.substr(i+1,s1.size()-i-1),s2.substr(i+1,s2.size()-i-1));
        post_order(s1.substr(1,i),s2.substr(0,i));
    }
}

int main(int argc,char *argv[]){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    string s1,s2;
    while(cin >> s1 >> s2){
        post_order(s1,s2);
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
        ans.clear();
    }
    return 0;
}
