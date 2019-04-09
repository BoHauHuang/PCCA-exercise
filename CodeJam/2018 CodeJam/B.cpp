#include<bits/stdc++.h>
using namespace std;
vector<int> L;

void TroubleSort(vector<int> &L){
	vector<int> odd;
	vector<int> even;
	int size = L.size();
	for(int i = 0 ; i < size ; i++){
		if(i%2) odd.push_back(L[i]);
		else even.push_back(L[i]);
	}
	
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	L.clear();
	
	for(int i = 0 ; i < size ; i++){
		if(i%2) L.push_back(odd[i/2]);
		else L.push_back(even[i/2]);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	int len, count = 1;
	
	while(T--){
		cin >> len;
		int in;
		for(int i = 0 ; i < len ; i++){
			cin >> in;
			L.push_back(in);
		}
		TroubleSort(L);
		
		bool success = true;
		for(int i = 0 ; i < L.size()-1 ; i++){
			if(L[i+1] < L[i]){
				cout << "Case #" << count++ << ": " << i << '\n'; 
				success = false;
				break;
			}
		}
		if(success) cout << "Case #" << count++ << ": OK" << '\n'; 
		
		L.clear(); 
	}
	
	return 0;
}
