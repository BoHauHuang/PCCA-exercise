#include<bits/stdc++.h>
using namespace std;
int sum,x[105];
bool cmp(int a,int b) {return b<a;}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		sum+=x[i];
	}
	sort(x+1,x+n+1,cmp);
	
	if(sum<m) cout<<-1;
	else if(sum==m) cout<<n;
	else {
		for(int i=1;i<=n;i++){
			int total = 0;
			for(int j=1;j<=n;j++)
				total += max(0,x[j]-(j-1)/i);
			if(total >= m){
				cout << i;
				return 0;	
			}	
		}		
	}
	return 0;
}
