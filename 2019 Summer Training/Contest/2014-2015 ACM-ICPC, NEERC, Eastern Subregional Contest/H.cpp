#include<bits/stdc++.h>
using namespace std;
int n, LowerID = 1, UpperID = 1;
string in;
struct node{
	int idx;
	char c;
};
deque<node> exist;
int ans[5010];

int main(){
	cin >> n >> in;
	
	for(int i = 0 ; i < in.size() ; i++){
		node now;
		now.c = in[i];
		if(in[i] >= 'a' && in[i] <= 'z') now.idx = LowerID++;
		else now.idx = UpperID++;
		
		if(exist.empty()) exist.push_back(now);
		else{
			node t = exist.back();
			if(t.c == now.c-'A'+'a'){
				ans[now.idx] = t.idx;
				exist.pop_back();
			}
			else if(t.c == now.c-'a'+'A'){
				ans[t.idx] = now.idx;
				exist.pop_back();
			}
			else exist.push_back(now);
		}
	}
	if(exist.empty()){
		for(auto x : ans)
			if(x) cout << x << " ";
		cout << endl;
	}
	else cout << "Impossible" << endl;
	
	return 0;
}
