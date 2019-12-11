#include<bits/stdc++.h>
using namespace std;
long long d, v1, v2;

int main(){
	while(cin >> d){
		if(!d) break;
		cin >> v1 >> v2;
		long long top, bot, g;
		
		if(v1 == v2){
			cout << "false" << endl;
			continue;
		}
		else if(v1 == 0){
			cout << "0" << endl;
			continue;
		}
		else if(v2 == 0){
			if(d%2) cout << (int)d/2 << endl;
			else cout << d << "/2" << endl;
			continue;
		}
		else if(v1 > 0 && v2 > 0){
			top = v1*d;
			bot = 2*abs(v1-v2);
		}
		else if(v1 > 0 && v2 < 0){
			v2 = -v2;
			top = v1*d;
			bot = 2*(v1+v2);
		}
		else if(v1 < 0 && v2 < 0){
			v1 = -v1;
			v2 = -v2;
			top = 2*d*abs(v1-v2)-v1*d;
			bot = 2*abs(v1-v2);
		}
		else if(v1 < 0 && v2 > 0){
			v1 = -v1;
			top = 2*d*(v1+v2)-v1*d;
			bot = 2*(v1+v2);
		}
		g = __gcd(top, bot);
		top /= g;
		bot /= g;
		
		if(top/bot >= d) top %= (d*bot);

		if(top%bot == 0) cout << top/bot << endl;	
		else cout << top << "/" << bot << endl;
	}
	
	return 0;
}
