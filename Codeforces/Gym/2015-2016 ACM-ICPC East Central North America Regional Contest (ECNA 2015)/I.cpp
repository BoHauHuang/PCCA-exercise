#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	
	cin >> n;
	char words[n][n], grid[n][n], g, tmp[n][n];
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> g;
			grid[i][j] = g;
			tmp[i][j] = g;
			words[i][j] = 'A';
		}
	}
	cin >> s;
	
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(grid[i][j] == '.'){
				if(words[i][j] == 'A') words[i][j] = s[cnt++];
				else{
					cout << "invalid grille\n";
					return 0;
				}
			} 
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			grid[i][j] = tmp[n-1-j][i];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			tmp[i][j] = grid[i][j];
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(grid[i][j] == '.'){
				if(words[i][j] == 'A') words[i][j] = s[cnt++];
				else{
					cout << "invalid grille\n";
					return 0;
				}
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			grid[i][j] = tmp[n-1-j][i];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			tmp[i][j] = grid[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(grid[i][j] == '.'){
				if(words[i][j] == 'A') words[i][j] = s[cnt++];
				else{
					cout << "invalid grille\n";
					return 0;
				}
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			grid[i][j] = tmp[n-1-j][i];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			tmp[i][j] = grid[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(grid[i][j] == '.'){
				if(words[i][j] == 'A') words[i][j] = s[cnt++];
				else{
					cout << "invalid grille\n";
					return 0;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(words[i][j] == 'A'){
				cout << "invalid grille\n";
				return 0;
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << words[i][j];
		}
	}
	
	return 0;
}

