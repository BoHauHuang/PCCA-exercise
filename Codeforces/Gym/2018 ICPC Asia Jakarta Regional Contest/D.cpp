#include<bits/stdc++.h>
using namespace std;
int r, c, ans = 0, mid_mud = 0;
bool has_mud = false;
 
int main(){
	cin >> r >> c;
	char graph[r][c];
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> graph[i][j];
		}
	}
 
	if(r > 2 && c > 2){
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if(graph[i][j] == '#' && !has_mud && !(i==0&&j==0) && !(i==0&&j==c-1) && !(i==r-1&&j==0) && !(i==r-1&&j==c-1) && (i==0||i==r-1||j==0||j==c-1) ) has_mud = true;
				if(graph[i][j] == '#' && !(!i || !j || i == r-1 || j == c-1)) mid_mud++;
			}
		}
		cout << (r-2)*(c-2)-mid_mud+(!has_mud) << endl;
	}
	else if(r > 2 && c == 2){
		int total = 0;
		for(int i = 1 ; i < r-1 ; i++)
			total += (graph[i][0] != '#' && graph[i][1] != '#');
		cout << total << endl;
	}
	else if(r == 2 && c > 2){
		int total = 0;
		for(int i = 1 ; i < c-1 ; i++)
			total += (graph[0][i] != '#' && graph[1][i] != '#');
		cout << total << endl;
	}
	else if(r == 1 && c > 1){
		int total = 0;
		for(int i = 1 ; i < c-1 ; i++)
			total += (graph[0][i] == '#');
		cout << r*c-2-total << endl;
	}
	else if(r > 1 && c == 1){
		int total = 0;
		for(int i = 1 ; i < r-1 ; i++)
			total += (graph[i][0] == '#');
		cout << r*c-2-total << endl;
	}
	else cout << "0" << endl;
 
	return 0;
}
