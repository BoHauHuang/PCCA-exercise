#include<bits/stdc++.h>
using namespace std;

int main(){
	char c;
	int q, id;
	cin >> q;
	map<int, int> book;
	
	cin >> c >> id;
	book[id] = 0;
	q--;
	int left = -1, right = 1;
	
	while(q--){
		cin >> c >> id;
		if(c == 'L') book[id] = left--;
		else if(c == 'R') book[id] = right++;
		else{
			int l = book[id]-left-1;
			int r = right-book[id]-1;
			cout << ((l>r)? r : l) << endl;
		}
	}
	
	return 0;
}
