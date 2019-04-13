#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int A[n][m], B[n][m];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> B[i][j];
		}
	}
	bool col = true, row = true;
	int A_col_cnt[m] = {0}, A_row_cnt[n] = {0} , B_col_cnt[m] = {0}, B_row_cnt[n] = {0};
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(A[i][j]) A_row_cnt[i]++;
			if(B[i][j]) B_row_cnt[i]++;
		}
	}
	for(int j = 0 ; j < m ; j++){
		for(int i = 0 ; i < n ; i++){
			if(A[i][j]) A_col_cnt[j]++;
			if(B[i][j]) B_col_cnt[j]++;
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		if(A_row_cnt[i]%2 != B_row_cnt[i]%2){
			row = false;
			break;
		}
	}
	for(int i = 0 ; i < m ; i++){
		if(A_col_cnt[i]%2 != B_col_cnt[i]%2){
			col = false;
			break;
		}
	}
	if(!col || !row) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}
