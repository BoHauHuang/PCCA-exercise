#include<bits/stdc++.h>
using namespace std;

int main(){
	string s, left = "", right = "";
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(i < (s.size()-1)/2) left += s[i];
		if(i > (s.size()-1)/2) right += s[i];
	}
	
	bool left_palindrome = true, right_palindrome = true;
	string left_rev = left;
	reverse(left_rev.begin(), left_rev.end());
	string right_rev = right;
	reverse(right_rev.begin(), right_rev.end());
	
	for(int i = 0 ; i < left.size() ; i++){
		if(left[i] != left_rev[i]) left_palindrome = false;
		if(right[i] != right_rev[i]) right_palindrome = false;
	}
	
	if(left == right && left_palindrome && right_palindrome) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
