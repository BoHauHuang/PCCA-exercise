#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		deque<int> space;
		int card[n], total = n;
		for(int i = 0 ; i < n ; i++)
			space.push_back(i);
		
		for(int i = 1 ; i <= total ; i++){
			for(int j = 0 ; j < i ; j++){
				int tmp = space.front();
				space.pop_front();
				space.push_back(tmp);
			}
			int pos = space.front();
			space.pop_front();
			card[pos] = i;
		}
		
		for(int i = 0 ; i < n ; i++)
			cout << card[i] << " ";
		cout << endl;
		
	}
	
	return 0;
}
