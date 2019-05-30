#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, cnt = 1;
	cin >> T;
	long long P, Q;
	while(T--){
		cin >> P >> Q;
		long long x, y;
		string dir;
		long long road[Q+1][Q+1];
		memset(road, 0, sizeof(road));
		
		for(int i = 0 ; i < P ; i++){
			cin >> x >> y >> dir;
			if(dir == "N"){
				for(int k = 0 ; k <= Q ; k++){
					for(int j = y+1 ; j <= Q ; j++){
						road[j][k]++;
					}
				}
				
			}
			else if(dir == "S"){
				for(int k = 0 ; k <= Q ; k++){
					for(int j = y-1 ; j >= 0 ; j--){
						road[j][k]++;
					}
				}
			}
			else if(dir == "E"){
				for(int k = 0 ; k <= Q ; k++){
					for(int j = x+1 ; j <= Q ; j++){
						road[k][j]++;
					}
				}
			}
			else if(dir == "W"){
				for(int k = 0 ; k <= Q ; k++){
					for(int j = x-1 ; j >= 0 ; j--){
						road[k][j]++;
					}
				}
			}
		}
		long long ans_x = 0, ans_y = 0, max = 0; 
		for(int i = 0 ; i <= Q ; i++){
			for(int j = 0 ; j <= Q ; j++){
				//cout << road[i][j] << " ";
				if(max < road[i][j]){
					ans_x = j;
					ans_y = i;
					max = road[i][j];
				}
			}
			//cout<<endl;
		}
		
		
		cout << "Case #" << cnt++ << ": " << ans_x << " " << ans_y << '\n';
	}
	
	return 0; 
}
