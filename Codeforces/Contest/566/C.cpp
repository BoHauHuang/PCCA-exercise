#include<bits/stdc++.h>
using namespace std;
map<char, int> vm;

// v_p: words can make pair
// v_s: words will be single, need to check its length
// pair<string, string>: origin string, "aeiou" string
deque<pair<string, string> > v[6], v_p, v_s;

vector<pair<string, string> > ans;

bool cmp(pair<string, string> lhs, pair<string, string> rhs){ return lhs.second.size() < rhs.second.size(); }

void init(){
	vm['a'] = 1;
	vm['e'] = 2;
	vm['i'] = 3;
	vm['o'] = 4;
	vm['u'] = 5;
}

char last_word(string s){ return s[s.size()-1]; }

int main(){
	init();
	int n;
	cin >> n;
	if(n < 2){
		cout << "0" << endl;
		return 0;
	}
	
	for(int i = 0 ; i < n ; i++){
		string in, out;
		cin >> in;
		for(int j = 0 ; j < in.size() ; j++)
			if(in[j] == 'a' || in[j] == 'e' || in[j] == 'i' || in[j] == 'o' || in[j] == 'u') out += in[j];
		
		if(out.size() > 0) v[vm[last_word(out)]].push_back(make_pair(in, out));
	}
	
	for(int i = 1 ; i < 6 ; i++)
		if(v[i].size()) sort(v[i].begin(), v[i].end(), cmp);
	
	for(int i = 1 ; i < 6 ; i++){
		while(!v[i].empty()){
			pair<string, string> a = v[i].front();
			v[i].pop_front();
			
			if(v[i].empty()){
				v_s.push_back(a);
				continue;
			}
			
			pair<string, string> b = v[i].front();
			v[i].pop_front();
			
			if(a.second.size() == b.second.size()){
				v_p.push_back(a);
				v_p.push_back(b);
			}
			else{
				v_s.push_back(a);
				v[i].push_front(b);
			}
		}
	}
	
	if(v_s.size() > 0){
		sort(v_s.begin(), v_s.end(), cmp);
		for(int i = 0 ; i < v_s.size()-1 ; i++){
			pair<string, string> a = v_s[i], b = v_s[i+1];
			
			if(a.second.size() == b.second.size() && v_p.size() > 1){
				ans.push_back(make_pair(a.first, v_p.front().first));
				v_p.pop_front();
				ans.push_back(make_pair(b.first, v_p.front().first));
				v_p.pop_front();
				
				i++;
			}
		}
	}
	
	while(v_p.size() > 3){
		string a1 = v_p.front().first;
		v_p.pop_front();
		string b1 = v_p.front().first;
		v_p.pop_front();
		
		string a2 = v_p.front().first;
		v_p.pop_front();
		string b2 = v_p.front().first;
		v_p.pop_front();
		
		ans.push_back(make_pair(a1, a2));
		ans.push_back(make_pair(b1, b2));
	}
	
	if(ans.size() > 0){
		cout << ans.size()/2 << endl;
		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	else cout << "0" << endl;
	
	return 0;
}
