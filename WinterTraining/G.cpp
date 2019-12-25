#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, ka, kb, total;
	cin >> a >> b >> ka >> kb >> total;
	cout << max(0, (total-((ka-1)*a+(kb-1)*b)));
	cout << " ";
	
	int sum = 0;
	if(ka > kb){
		while(b > 0 && total >= kb){
			sum++;
			total -= kb;
			b--;
		}
		while(a > 0 && total >= ka){
			sum++;
			total -= ka;
			a--;
		}
	}
	else{
		while(a > 0 && total >= ka){
			sum++;
			total -= ka;
			a--;
		}
		while(b > 0 && total >= kb){
			sum++;
			total -= kb;
			b--;
		}
	}
	cout << sum;
	
	return 0;
}
