#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int s, g;
	cin >> s >> g;
	if(s%g || s/g == 1) cout << "-1" << endl;
	else cout << g << " " << g*((s/g)-1) << endl;
	
	return 0;
}
