#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, in;
	cin >> n;
	vector<int> color;
	set<int> diff;
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		color.push_back(in);
		diff.insert(in);
	}
	int max = 0;
	map<int, int> last;
	for(int i = 0 ; i < n ; i++){
		if(last[color[i]] == 0){
			for(int j = n-1 ; j > i+max ; j--){
				if(color[i] != color[j]){
					max = j-i;
					last[color[i]] = max;
					diff.erase(color[i]);
					break;
				}
			}
		}
		
		if(i+max >= n || diff.empty()) break;
	}
	cout << max << '\n';
	
	return 0;
}
