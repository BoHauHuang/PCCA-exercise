#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<long long, long long> lhs, pair<long long, long long> rhs){
	if(lhs.first == rhs.first) return lhs.second < rhs.second;
	return lhs.first < rhs.first;
}
 
int main(){
	long long n;
	cin >> n;
	long long c, r;
	
	bool win = false;
	deque<pair<long long, long long> > card;
	map<pair<long long, long long>, long long> pos;
	vector<long long> ans;
	
	for(int i = 0 ; i < n ; i++){
		cin >> c >> r;
		card.push_back(make_pair(c, r));
		pos[make_pair(c, r)] = i+1;
	}
	
	sort(card.begin(), card.end(), cmp);
	
	long long money = 1;
	
	while(!card.empty()){
		priority_queue<pair<long long, long long> > gain;
		
		// push cards into queue
		while(card.front().first <= money && !card.empty()){
			gain.push(make_pair(card.front().second, card.front().first));
			card.pop_front();
		}
		
		// buy last card: win
		if(card.empty()){
			ans.push_back(n);
			win = true;
			break;
		}
		
		// cannot buy any card
		if(gain.empty()) break;
		// find the maximum gain
		else{
			//cout << "pick: " << gain.top().second << " " << gain.top().first << endl;
			long long max_gain = 0, m;
			bool ok = false;
			while(!gain.empty()){
				long long p = pos[make_pair(gain.top().second, gain.top().first)];
				if(p == n){
					ans.push_back(n);
					ok = true;
					win = true;
					break;
				}
				
				if(gain.top().first > max_gain){
					m = pos[make_pair(gain.top().second, gain.top().first)];
					max_gain = gain.top().first;
				}
				gain.pop();
			}
			if(!ok) ans.push_back(m);
			money = max_gain;
		}
	}
	
	if(win){
		cout << ans.size() << endl;
		for(auto x:ans)
			cout << x << " ";
		cout << endl;
	}
	else cout << "No such luck" << endl;
	
	return 0;
}
