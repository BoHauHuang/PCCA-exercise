#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string a;
	int num[10];
	memset(num, 0, sizeof(num));
	cin >> n >> a;
	for(int i  = 1 ; i < 10 ; i++)
		cin >> num[i];

	int s = 0;
	for(int i = 0 ; i < a.size() ; i++){
		if((int)a[i]-'0' < num[(int)a[i]-'0'] && s == 0){
            cout << (char)(num[(int)a[i]-'0']+'0');
            s = 1;
		}
		else if((int)a[i]-'0' > num[(int)a[i]-'0'] && s == 1){
            cout << a[i];
            s = 2;
		}
		else if(s == 1) cout << (char)(num[(int)a[i]-'0']+'0');
		else cout << a[i];
	}

	return 0;
}
