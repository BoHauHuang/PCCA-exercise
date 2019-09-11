#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c ;
	cin >> a >> b >> c;
	int aw = a/3, bw = b/2, cw = c/2, min;
	min = aw;
	if(bw < min) min = bw;
	if(cw < min) min = cw;
	a -= min*3;
	b -= min*2;
	c -= min*2;
	int len = min*7, max = min*7, tmp_A = a, tmp_B = b, tmp_C = c;
	for(int i = 1 ; i <= 7 ; i++){
		int now = i;
		len = min*7;
		a = tmp_A;
		b = tmp_B;
		c = tmp_C;
		while(a || b || c){
			if(now == 1 || now == 4 || now == 7){
				if(a) a--;
				else break;
			}
			else if(now == 2 || now == 6){
				if(b) b--;
				else break;
			}
			else{
				if(c) c--;
				else break;
			}
			len++;
			now++;
			if(now == 8) now = 1;
		}
		if(max < len) max = len;
	}
	
	cout << max << endl;
	
	return 0;
}
