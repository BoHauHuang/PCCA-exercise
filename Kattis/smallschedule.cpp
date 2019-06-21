#include<bits/stdc++.h>
using namespace std;

int main(){
	int Q, M, S, L;
	cin >> Q >> M >> S >> L;
	long long int time = 0;
	
	time += ((L/M)*Q);
	L -= ((L/M)*M);
	
	if(L){
		time+=Q;
		
		if((M-L)*Q < S){
			int more = S-(M-L)*Q;
			time += (more/M);
			time += (more%M != 0);
		}
	}
	else{
		time += (S/M);
		time += (S%M != 0);
	}
	cout << time << endl;
	return 0;
}
