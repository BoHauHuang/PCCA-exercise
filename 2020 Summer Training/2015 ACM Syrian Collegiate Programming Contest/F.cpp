#include<bits/stdc++.h>
using namespace std;

int number[6];

bool pick2(int a, int b){
	set<int> num;
		
	for(int i = 0 ; i < 7 ; i++)
		if(i != a && i != b) num.insert(number[i]);
	
	if(number[a]+number[b] <= 5) num.insert(number[a]+number[b]);
	
	return (num.size() == 5);
}

bool pick4(int a, int b, int c, int d){
	set<int> num;
	
	for(int i = 0 ; i < 7 ; i++)
		if(i != a && i != b && i != c && i != d) num.insert(number[i]);
	
	if(number[a]+number[b] <= 5) num.insert(number[a]+number[b]);
	if(number[c]+number[d] <= 5) num.insert(number[c]+number[d]);
	
	return (num.size() == 5);
}

int main(){
	int T;
	string s;
	cin >> T;
	while(T--){
		cin >> s;
		int cnt[6];
		bool done = true;
		memset(cnt, 0, sizeof(cnt));
		memset(number, 0, sizeof(number));
		
		for(int i = 0 ; i < s.size() ; i++){
			cnt[(int)s[i]-'A'+1]++;
			number[i] = (int)s[i]-'A'+1;
		}
		
		for(int i = 1 ; i <= 5 ; i++)
			if(cnt[i] == 0) done = false;
			
		if(!done){
			for(int i = 0 ; i < s.size() ; i++){
				for(int j = i+1 ; j < s.size() ; j++){
					done = done || pick2(i, j);
					for(int k = j+1 ; k < s.size() ; k++){
						for(int l = k+1 ; l < s.size() ; l++){
							done = done || pick4(i, j, k, l) || pick4(i, l, k, j) || pick4(i, k, j, l);
						}
					}
				}
			}
		}
		cout << ((done)? "YES" : "NO") << endl;
	}
	return 0;
}

