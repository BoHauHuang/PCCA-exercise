#include<bits/stdc++.h>
using namespace std;
 
struct dices{
	int low;
	int high;	
} emma[2], gunn[2];
 
int main(){
	for(int i = 0 ; i < 2 ; i++)
		cin >> gunn[i].low >> gunn[i].high;
	for(int i = 0 ; i < 2 ; i++)
		cin >> emma[i].low >> emma[i].high;
	
	int emma_max = emma[0].high+emma[1].high, gunn_max = gunn[0].high+gunn[1].high, emma_min = emma[0].low+emma[1].low, gunn_min = gunn[0].low+gunn[1].low;
	int emma_win = emma_max-gunn_max+emma_min-gunn_min;
	
	if(emma_win > 0) cout << "Emma" << endl;
	else if(emma_win == 0) cout << "Tie" << endl;
	else cout << "Gunnar" << endl;
	
	return 0;
}
