#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char *argv[]){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    string s;
    int n;
    cin >> n;
    long long l1,l2,r1,r2,ans1,ans2;
    int i;
    while(n--){
        cin >> s;
        l1=0;
        l2=1;
        r1=1;
        r2=0;
        ans1=1;
        ans2=1;
        for(i=0;i<s.size();i++){
            if(s[i]=='R'){
                l1=ans1;
                l2=ans2;
                ans1+=r1;
                ans2+=r2;
            }
            else if(s[i]=='L'){
                r1=ans1;
                r2=ans2;
                ans1+=l1;
                ans2+=l2;
            }
        }
        cout << ans1 << "/" << ans2 << endl;
    }
    return 0;
}
