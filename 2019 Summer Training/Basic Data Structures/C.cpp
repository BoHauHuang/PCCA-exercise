#include<bits/stdc++.h>
using namespace std;
deque<int> cards;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		if(!n) return 0;
		if(n == 1){
			cout << "Discarded cards:" << '\n' << "Remaining card: 1" << '\n';
			continue; 
		}
		cards.clear();
		for(int i = 1 ; i <= n ; i++)
			cards.push_back(i);
		
		cout << "Discarded cards: " << cards.front();
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
		
		while(cards.size() != 1){
			cout << ", " << cards.front();
			cards.pop_front();
			cards.push_back(cards.front());
			cards.pop_front();
		}
		
		cout << '\n';
		cout << "Remaining card: " << cards.front() << '\n';
	}
}
