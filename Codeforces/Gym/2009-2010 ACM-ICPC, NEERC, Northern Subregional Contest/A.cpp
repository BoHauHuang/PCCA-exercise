#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin("auxiliary.in");
	ofstream cout("auxiliary.out");
	
	string s;
	cin >> s;
	
	stack<char> expr;
	
	int left = 0, right = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(expr.empty() && s[i] == ')') left++;
		else if(!expr.empty() && s[i] == ')') expr.pop();
		else if(s[i] == '(') expr.push(s[i]);
	}
	for(int i = 0 ; i < left ; i++)
		s = "("+s;
	for(int i = 0 ; i < expr.size() ; i++)
		s += ")";
	
	for(int i = 0 ; i < s.size() ; i++){
		if(!i && s[i] == '+') cout << "0";
		cout << s[i];
		if((s[i] == ')' && s[i+1] == '(') || (s[i] <= '9' && s[i] >= '0' && s[i+1] == '(') || (s[i+1] <= '9' && s[i+1] >= '0' && s[i] == ')')) cout << "+";
		if((s[i] == '(' && s[i+1] == ')') || (s[i] == '(' && s[i+1] == '+') || (s[i] == '+' && s[i+1] == ')') || (i == s.size()-1 && s[i] == '+') || (s[i] == '+' && s[i+1] == '+')) cout << "0";
	}
	
	return 0;
}

