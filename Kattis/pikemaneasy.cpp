#include<bits/stdc++.h>
#define BIG 1000000007
using namespace std;

int main(){
	long long int N, T, A, B, C, t0;
	cin >> N >> T >> A >> B >> C >> t0;
	
	unsigned long long int time = 0, problem = 0;
	vector<long long int> t(N,0);
	vector<long long int> clk(N,0);
	
	t[0] = t0;
	
	for(int i = 1 ; i < N ; i++)
		t[i] = ((A*t[i-1]+B)%C)+1;
		
	sort(t.begin(), t.end());
	
	clk[0] = t[0];
	for(int i = 1 ; i < N ; i++)
		clk[i] = clk[i-1]+t[i];
	
	for(int i = 0 ; i < N ; i++){
		if(clk[i] <= T){
			time += clk[i];
			time %= BIG;
			problem++;
		}
		else break;
	}
	
	cout << problem << " " << (time%BIG) << endl;
	
	return 0;
} 
