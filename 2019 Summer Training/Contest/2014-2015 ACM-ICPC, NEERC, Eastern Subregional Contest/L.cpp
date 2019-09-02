#include<bits/stdc++.h>
using namespace std;
long long int n, ans = 0, now = 1;
map<char, int> sec1, sec2, sec3;
queue<int> pos;

void init(){
	sec1['A']++;
	sec1['P']++;
	sec1['O']++;
	sec1['R']++;
	
	sec2['B']++;
	sec2['M']++;
	sec2['S']++;
	
	sec3['D']++;
	sec3['G']++;
	sec3['J']++;
	sec3['K']++;
	sec3['T']++;
	sec3['W']++;
}

void step_to(int p){ 
	ans += abs(now-p);
	now = p;
}

int main(){
	string in;
	cin >> n;
	init();
	step_to(1);
		
	while(n--){
		cin >> in;
		if(sec1[in[0]] && now != 1) step_to(1);
		if(sec2[in[0]] && now != 2) step_to(2);
		if(sec3[in[0]] && now != 3) step_to(3);
	}
	
	cout << ans << endl;
	
	return 0;
}
