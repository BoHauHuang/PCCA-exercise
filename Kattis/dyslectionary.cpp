#include<bits/stdc++.h>
using namespace std;

void show(vector<string> &word){
	int max = 0;
	vector<string> rev_word;
	
	for(int i = 0 ; i < word.size() ; i++)
    	if(max < word[i].size()) max = word[i].size();
	
	for(auto &w : word){
		reverse(w.begin(), w.end());
	}
    sort(word.begin(), word.end());
    
    for(auto &w : word){
    	reverse(w.begin(), w.end());
	}
    
    for(auto &w : word){
    	string tmp;
    	tmp.resize(max-w.size(), ' ');
    	tmp += w;
    	
    	cout << tmp << endl;
	}
}

int main(){
    string s;
    vector<string> word;
    
    while(getline(cin, s)){
        if(s.empty()){
            show(word);
            
            cout << endl;
            word.clear();
        }
        else word.push_back(s);
    }
	show(word);
    return 0;
}
