#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin >> n;
    vector< pair<long long,long long> > p;
    vector<long long> ans;
    long long a,b;
    for(i=0;i<n;i++){
        cin >> a >> b;
        p.push_back(pair<long long,long long>(b,a));
    }
    sort(p.begin(),p.end());
    i=0;
    a=p[i].first;
    ans.push_back(a);
    i++;
    while(i<p.size()){
        if(p[i].first>=a&&p[i].second<=a){
            i++;
        }
        else{
            a=p[i].first;
            ans.push_back(a);
            i++;
        }
    }
    cout << ans.size() << '\n';
    for(i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
	return 0;
}
