#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, in;
	cin >> t;
	while(t--){
		cin >> n;
		deque<int> a;
		for(int i = 0 ; i < n ; i++){
			cin >> in;
			a.push_back(in);
		}
		bool is_a = true;
		long long p1 = 0, p2 = 0, now = a.front(), pre = 0, ans = 1;
		a.pop_front();
		p1+=now;
		pre=now;
		is_a = false;
		
		while(!a.empty()){
			now = 0;
			while(now <= pre && !a.empty()){
				if(is_a){
					now += a.front();
					a.pop_front();
				}
				else{
					now += a.back();
					a.pop_back();
				}
			}
			ans++;
			
			if(is_a) p1+=now;
			else p2+=now;
			
			pre=now;
			is_a = !is_a;
		}
		cout << ans << " " << p1 << " " << p2 << endl;
	}


	return 0;
}

