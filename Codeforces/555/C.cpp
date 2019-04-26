#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, in;
    cin >> n;
    deque<int> num;
    vector<int> ans;
    vector<char> how;

    for(int i = 0 ; i < n ; i++){
        cin >> in;
        num.push_back(in);
    }
    bool succ = true;
    while(succ){
        if(ans.empty()){
            int take;
            if(num.front() < num.back()){
                    take = num.front();
                    num.pop_front();
                    how.push_back('L');
            }
            else{
                    take = num.back();
                    num.pop_back();
                    how.push_back('R');
            }
            ans.push_back(take);
        }
        int left = num.front(), right = num.back(), take;

        if(left > ans.back() && right > ans.back()){
            if(left < right){
                take = left;
                how.push_back('L');
                num.pop_front();
            }
            else{
                take = right;
                how.push_back('R');
                num.pop_back();
            }
            ans.push_back(take);
        }
        else if(left > ans.back() && right < ans.back()){
            take = left;
            num.pop_front();
            how.push_back('L');
            ans.push_back(take);
        }
        else if(left < ans.back() && right > ans.back()){
            take = right;
            num.pop_back();
            how.push_back('R');
            ans.push_back(take);
        }
        else if(left == right && ans.back() < num.back()){
            int take = num.back();
            num.pop_back();
            how.push_back('R');
            ans.push_back(take);
        }
        else succ = false;
    }

    cout << ans.size() << endl;
    for(int i = 0 ; i < how.size() ; i++)
            cout << how[i];
    cout << endl;

    return 0;
}
