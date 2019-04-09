
 #include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int num[n];
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];
	sort(num, num+sizeof(num)/sizeof(int));
	
	int x, y;
	x = num[n-1];
	map<int, int> cnt;
	int counter = 1;
	for(int i = n-1 ; i >= 0 ; i--){
		if(cnt[num[i]] == 0 && num[i] > 0 && !(x%num[i])){
			cnt[num[i]] = 1;
			num[i] = -1;
			counter++;
		}
	}
	sort(num, num+sizeof(num)/sizeof(int));
	y = num[n-1];
	
	cout << x << " " << y << endl;

	return 0;
}
