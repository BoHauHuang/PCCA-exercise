#include<bits/stdc++.h>
#define NUM 27
#define BIG 10000000
using namespace std;

int main(){
	string a, b, c;
	cin >> a >> b >> c;
	
	int cnt_a[NUM], cnt_b[NUM], cnt_c[NUM], tmp_a[NUM];
	memset(cnt_a, 0, sizeof(cnt_a));
	memset(cnt_b, 0, sizeof(cnt_b));
	memset(cnt_c, 0, sizeof(cnt_c));
	memset(tmp_a, 0, sizeof(tmp_a));
	
	for(int i = 0 ; i < a.size() ; i++)
		cnt_a[a[i]-'a']++;
	for(int i = 0 ; i < b.size() ; i++)
		cnt_b[b[i]-'a']++;
	for(int i = 0 ; i < c.size() ; i++)
		cnt_c[c[i]-'a']++;
	
	int b_max = BIG, c_max = BIG;
	
	for(int i = 0 ; i < NUM ; i++)
		if(cnt_b[i]) b_max = (b_max > (cnt_a[i]/cnt_b[i]))? cnt_a[i]/cnt_b[i] : b_max;
	for(int i = 0 ; i < NUM ; i++)
		if(cnt_c[i]) c_max = (c_max > (cnt_a[i]/cnt_c[i]))? cnt_a[i]/cnt_c[i] : c_max;
	
	int total = 0, c_time = 0, b_time = 0;
	if(b_max > c_max){
		for(int i = 1 ; i <= b_max ; i++){
			for(int j = 0 ; j < NUM ; j++)
				tmp_a[j] = cnt_a[j];
				
			for(int j = 0 ; j < b.size() ; j++)
				tmp_a[b[j]-'a'] -= i;
			
			int cnt = BIG;
			for(int j = 0 ; j < NUM ; j++)
				if(cnt_c[j]) cnt = (cnt > (tmp_a[j]/cnt_c[j]))? tmp_a[j]/cnt_c[j] : cnt;
			
			if(cnt+i > total){
				total = cnt+i;
				b_time = i;
				c_time = cnt;
			}
		}
	}
	else{
		for(int i = 1 ; i <= c_max ; i++){
			for(int j = 0 ; j < NUM ; j++)
				tmp_a[j] = cnt_a[j];
				
			for(int j = 0 ; j < c.size() ; j++)
				tmp_a[c[j]-'a'] -= i;
			
			int cnt = BIG;
			for(int j = 0 ; j < NUM ; j++)
				if(cnt_b[j]) cnt = (cnt > (tmp_a[j]/cnt_b[j]))? tmp_a[j]/cnt_b[j] : cnt;
			
			if(cnt+i > total){
				total = cnt+i;
				b_time = cnt;
				c_time = i;
			}
		}
	}
	
	for(int i = 0 ; i < b_time ; i++)
		cout << b;
	for(int i = 0 ; i < c_time ; i++)
		cout << c;
		
	for(int i = 0 ; i < b.size() ; i++)
		cnt_a[b[i]-'a'] -= b_time;
	for(int i = 0 ; i < c.size() ; i++)
		cnt_a[c[i]-'a'] -= c_time;
	
	for(int i = 0 ; i < NUM ; i++){
		if(cnt_a[i]){
			for(int j = 0 ; j < cnt_a[i] ; j++)
				cout << (char)(i+'a');
		}
	}
	
	return 0;
}
