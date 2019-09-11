#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int num[n*n];
	
	if(n == 1){
		cin >> num[0];
		cout << "YES" << endl << num[0] << endl;
	}
	else{
		if(!(n%2)){
			int block_size = (n/2)+1;
			int cnt[1001], block[block_size][block_size], row = 1, col = 1;
			memset(cnt, 0, sizeof(cnt));
			bool success = true;
			
			for(int i = 0 ; i < n*n ; i++){
				cin >> num[i];
				cnt[num[i]]++;
				if(cnt[num[i]] == 4){
					block[row][col] = num[i];
					col++;
					if(col == block_size){
						col = 1;
						row++;
					}
					cnt[num[i]] = 0;
				}
			}
			for(int i = 1 ; i <= 1000 ; i++){
				if(cnt[i] != 0){
					success = false;
					break;
				}
			}
			if(!success) cout << "NO" << endl;
			else{
				cout << "YES" << endl;
				int print_row = 1, print_col = 1, state = 1;
				
				for(int i = 0 ; i < n*n ; i++){
					if(state == 1){
						cout << block[print_row][print_col] << " ";
						print_col++;
						if(print_col == block_size){
							state = 2;
							print_col = block_size-1;
						}
					}
					else if(state == 2){
						cout << block[print_row][print_col] << " ";
						print_col--;
						if(print_col == 0){
							print_row++;
							
							if(print_row == block_size){
								state = 3;
								print_row = block_size-1;
							}
							else state = 1;
							
							print_col = 1;
							
							cout << endl;
						}
					}
					else if(state == 3){
						cout << block[print_row][print_col] << " ";
						print_col++;
						if(print_col == block_size){
							state = 4;
							print_col = block_size-1;
						}
					}
					else if(state == 4){
						cout << block[print_row][print_col] << " ";
						print_col--;
						if(print_col == 0){
							print_row--;
							print_col = 1;
							state = 3;
							
							cout << endl;
							if(print_row == 0) break;
						}
					}
				}
			}
		}
		else{
			int block_size = (n/2)+1;
			int cnt[1001], block[block_size][block_size], row = 1, col = 1, cross_y[block_size], cross_x[block_size], cx = 1, cy = 1, middle = -1;
			memset(cnt, 0, sizeof(cnt));
			bool success = true, blo = false, mid_find = false;
			
			for(int i = 0 ; i < n*n ; i++){
				cin >> num[i];
				cnt[num[i]]++;
				if(!blo && cnt[num[i]] == 4){
					block[row][col] = num[i];
					col++;
					if(col == block_size){
						col = 1;
						row++;
						if(row == block_size) blo = true;
					}
					cnt[num[i]] = 0;
				}
			}
			
			for(int i = 1 ; i <= 1000 ; i++){
				if(cnt[i] >= 2){
					for(cx ; cx < block_size && cnt[i] >= 2 ; cx++){
						cross_x[cx] = i;
						cnt[i] -= 2;
					}
					if(cx == block_size) break;
				}
			}
			
			for(int i = 1 ; i <= 1000 ; i++){
				if(cnt[i] >= 2){
					for(cy ; cy < block_size && cnt[i] >= 2 ; cy++){
						cross_y[cy] = i;
						cnt[i] -= 2;
					}
					if(cy == block_size) break;
				}
			}
			
			for(int i = 1 ; i <= 1000 ; i++){
				if(cnt[i] == 1){
					middle = i;
					cnt[i]--;
					break;
				}
			}
			for(int i = 1 ; i <= 1000 ; i++){
				if(cnt[i]){
					success = false;
					break;
				}
			}
			
			if(!success) cout << "NO" << endl;
			else{
				cout << "YES" << endl;
				int print_row = 1, print_col = 1, state = 1, print_y = 1, print_x = 1;
				
				for(int i = 0 ; i < n*n ; i++){
					if(state == 1){
						cout << block[print_row][print_col] << " ";
						print_col++;
						if(print_col == block_size){
							state = 2;
							print_col = block_size-1;
						}
					}
					else if(state == 2){
						cout << cross_y[print_y++] << " ";
						if(print_y == block_size) print_y = block_size-1;
						state = 3;
					}
					else if(state == 3){
						cout << block[print_row][print_col] << " ";
						print_col--;
						if(print_col == 0){
							print_row++;
							if(print_row == block_size){
								state = 4;
								print_row = block_size-1;
							}
							else state = 1;
							
							print_col = 1;
							
							cout << endl;
						}
					}
					else if(state == 4){
						for(int i = 1 ; i < block_size ; i++) cout << cross_x[i] << " ";
						cout << middle << " ";
						for(int i = block_size-1 ; i >= 1 ; i--) cout << cross_x[i] << " ";
						cout << endl;
						state = 5;
					}
					else if(state == 5){
						cout << block[print_row][print_col] << " ";
						print_col++;
						if(print_col == block_size){
							print_col = block_size-1;
							state = 6;
						}
					}
					else if(state == 6){
						cout << cross_y[print_y--] << " ";
						state = 7;
					}
					else if(state == 7){
						cout << block[print_row][print_col] << " ";
						print_col--;
						if(print_col == 0){
							print_row--;
							print_col = 1;
							state = 5;
							cout << endl;
							if(print_row == 0) break;
						}
					}
				}
			}
		}
	}
	
	return 0;
}
