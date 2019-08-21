#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n];
    int i;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int ans,ans1,ans2;
    ans1=0;
    ans2=m;
    int c,t;
    while(ans1+1<ans2){
        ans=(ans1+ans2)/2;
        c=0;
        t=ans;
        for(i=0;i<n;i++){
            if(a[i]<=c){
                c++;
            }
            else if(a[i]>c&&t>0){
                c++;
                t--;
            }
        }
        if(c>=m){
            ans2=ans;
        }
        else if(c<m){
            ans1=ans;
        }
    }
    ans=ans1;
    c=0;
    t=ans;
    for(i=0;i<n;i++){
        if(a[i]<=c){
            c++;
        }
        else if(a[i]>c&&t>0){
            c++;
            t--;
        }
    }
    if(c>=m){
        cout << ans1;
    }
    else if(c<m){
        cout << ans2;
    }
	return 0;
}
