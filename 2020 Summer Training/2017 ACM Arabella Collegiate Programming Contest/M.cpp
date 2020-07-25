#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t, c, n;
	double v;
	char s[100000];
	
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &c, &n);
		double total = 0;
		unordered_map<string, double> price;
		
		price["JD"] = 1.00;
		for(int i = 0 ; i < c ; i++){
			scanf("%s %lf", s, &v);
			price[s] = v;
		}
		
		for(int i = 0 ; i < n ; i++){
			scanf("%lf %s", &v, s);
			total += price[s]*v;
		}
		printf("%.6f\n", total);
	}
	return 0;
}

