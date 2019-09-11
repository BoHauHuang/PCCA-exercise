#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, b, a, in;
	vector<int> path;
	cin >> n >> b >> a;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		path.push_back(in);
	}
	int len = 0, bat = b, acc = a;
	
	for(int i = 0 ; i < n ; i++){
		if(!acc && !bat) break;
		if(path[i] == 1){
			if(b == 0){
				acc--;
				len++;
			}
			else{
				if(bat == 0){
					acc--;
					len++;
				}
				else if(bat && acc == a && !a){
					bat--;
					len++;
				}
				else if(bat && acc < a && a){
					bat--;
					len++;
					acc++;
				}
				else if(bat && acc == a && a){
					acc--;
					len++;
				}
			}
		}
		else if(path[i] == 0){
			if(acc){
				acc--;
				len++;
			}
			else{
				bat--;
				len++;
			}
		}
	}
	cout << len << '\n';
	
	return 0;
}
