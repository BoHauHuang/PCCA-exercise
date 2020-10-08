#include<bits/stdc++.h>
using namespace std;

long long trans(long long p, long long x){
	if(p < x) return x-p;
	if(p == x) return 0;
	return p-x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long p1, p2, q1, q2, t, x;
	cin >> p1 >> q1 >> p2 >> q2 >> t;
	long long sum = 0;
	while(t--){
		cin >> x;

		long long tp1 = trans(p1, x), tp2 = trans(p2, x), tq1 = trans(q1, x), tq2 = trans(q2, x);

		if(x < q1 && x > p1){
			if(q1-x >= x-p1){
				tp1 = 0;
			}
			else{
				tq1 = 0;
			}
		}
		if(x < q2 && x > p2){
			if(q2-x >= x-p2){
				tp2 = 0;
			}
			else{
				tq2 = 0;
			}
		}
		
		
		if(tp1 > tq1) swap(tp1, tq1);
		if(tp2 > tq2) swap(tp2, tq2);
		if(tp1 > tp2){
			swap(tp1, tp2);
			swap(tq1, tq2);
		}

		if(tq1 < tp2){
			cout << abs(tq1-tp1)+abs(tq2-tp2) << '\n';
			continue;
		}

		if(tq1 >= tq2){
			cout << abs(tq1-tp1) << '\n';
		}
		else if(tq1 < tq2){
			cout << abs(tq1-tp1)+abs(tq2-tp2)-abs(tp2-tq1) << '\n';
		}
	}


	return 0;
}