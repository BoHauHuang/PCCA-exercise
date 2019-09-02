#include<bits/stdc++.h>
using namespace std;
long long int ans = 0;
string ina, inb;
deque<char> a, b;

int main(){
	cin >> ina >> inb;
	
	for(int i = 0 ; i < ina.size() ; i++)
		a.push_back(ina[i]);
	for(int i = 0 ; i < inb.size() ; i++)
		b.push_back(inb[i]);
	
	while(!a.empty() || !b.empty()){
		if((a.front() == 'L' && b.front() == 'F') || (a.front() == 'L' && b.front() == 'R') || (a.empty() && !b.empty())){ // a wanna go left
			ans++;
			b.pop_front();
		}
		else if((a.front() == 'F' && b.front() == 'L') || (a.front() == 'R' && b.front() == 'L') || (!a.empty() && b.empty())){ // b wanna go left
			ans++;
			a.pop_front();
		}
		else{
			ans++;
			a.pop_front();
			b.pop_front();
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
