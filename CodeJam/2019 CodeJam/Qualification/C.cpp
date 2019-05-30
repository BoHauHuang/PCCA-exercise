#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if(!b) return a;
	else gcd(b, a%b);
}

int main(){
	int T, L, count = 1;
	string N;
	cin >> T;
	while(T--){
		cin >> N >> L;
		vector<long long> mul;
		int in;
		for(int i = 0 ; i < L ; i++){
			cin >> in;
			mul.push_back(in);
		}
		deque<long long> possible;
		
		for(int i = 0 ; i < mul.size()-1 ; i++){
			long long g = (gcd(mul[i], mul[i+1]) == mul[i])? 0 : gcd(mul[i],mul[i+1]);
			if(g){
				int idx = i;
				long long hold = mul[i]/g;
				while(idx >= 0){
					possible.push_front(hold);
					idx--;
					hold = mul[idx]/hold;
				}
				possible.push_back(g);
				hold = mul[i+1]/g;
				idx = i+1;
				while(idx < mul.size()){
					possible.push_back(hold);
					idx++;
					hold = mul[idx]/hold;
				}
				break;
			}
		}
		
		deque<long long> origin;
		origin = possible;
		sort(possible.begin(), possible.end());
		map<long long, char> prime_to_alph;
		int cnt = 0;
		for(int i = 0 ; i < possible.size() ; i++){
			if(prime_to_alph[possible[i]] == 0) prime_to_alph[possible[i]] = 'A'+cnt++;
		}
		
		cout << "Case #" << count++ << ": ";
		
		for(int i = 0 ; i < origin.size() ; i++){
			cout << prime_to_alph[origin[i]];
		}
		cout << endl;
	}
	
	return 0;
}
