#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, in, total;
	cin >> t;
	while(t--){
		stack<int> price;
		cin >> n;
		total = n;
		while(total--){
			cin >> in;
			if(price.empty() || price.top() <= in) price.push(in);
			else{
				while(!price.empty() && price.top() > in) price.pop();
				price.push(in);
			}
		}
		cout << n-price.size() << endl;
	}
	
	return 0;
}
