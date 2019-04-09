#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	int s[n];
	vector<int> student;
 	for(int i = 0 ; i < n ; i++){
		cin >> s[i];
		student.push_back(s[i]);
	}
	sort(student.begin(), student.end());
	int sum = 0;
	for(int i = 1 ; i < n ; i+=2)
		sum += student[i]-student[i-1];	
	cout << sum << endl;
	return 0;
} 
