#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int cnt[k], in;
	vector<int> num;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0 ; i < n ; i++){
		cin >> in;
		num.push_back(in);
	}
	for(int i = 0 ; i < num.size() ; i++){
		cnt[num[i]%k]++;
	}
	
	int mid = (k%2)? (k+1)/2 : k/2;
	int j = k-1, max = 0;
	for(int i = 1 ; i < mid ; i++){
		int p = (cnt[i] > cnt[j])? cnt[j] : cnt[i];
		max += p*2;
		j--;
	}
	
	max += ((cnt[0]%2)? cnt[0]-1 : cnt[0]);
	if(!(k%2)) max += ((cnt[mid]%2)? cnt[mid]-1 : cnt[mid]);

	cout << max << endl;
	
	return 0;
}
