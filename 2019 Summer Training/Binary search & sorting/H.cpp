#include<bits/stdc++.h>
#define BIG 100005
#define INF 200000010
using namespace std;

struct table{
	int len;
	int energy;
} leg[BIG];

int n, ans = INF, back[BIG], max_remain, cost;
map<int, int> cnt, safe;

bool cmp(table lhs, table rhs){ return lhs.len < rhs.len; }

void init(){ memset(back, 0, sizeof(back)); }

int main(){
	init();
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> leg[i].len;
		cnt[leg[i].len]++;
	}
	
	for(int i = 0 ; i < n ; i++){
		cin >> leg[i].energy;
		back[leg[i].len] += leg[i].energy;
	}
	
	for(int i = BIG-2 ; i >= 0 ; i--)
		back[i] += back[i+1];
		
	sort(leg, leg+n, cmp);
	
	for(int i = 0 ; i < n ; i++){
		max_remain = cnt[leg[i].len]-1;
		cost = back[leg[i].len+1];
		
		for(auto it = safe.rbegin() ; it != safe.rend() ; it++){
			if(max_remain >= (*it).second) max_remain -= (*it).second;
			else{
				cost += (*it).first*((*it).second-max_remain);
				max_remain = 0;
			}
		}
		safe[leg[i].energy]++;
		ans = (ans > cost)? cost : ans;
	}
	
	cout << ans << endl;
	
	return 0;
}
