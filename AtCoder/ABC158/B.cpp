#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int N, A, B;
	cin >> N >> A >> B;
	cout << (A*(N/(A+B)) + min(N%(A+B), A)) << endl;

	return 0;
}

