#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	cout << ((N*A < B)? N*A : B) << endl;
	return 0;
}

