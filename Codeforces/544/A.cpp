#include<bits/stdc++.h>
using namespace std;

int main(){
	int h1, h2, m1, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	int md, hd;
	
	if(m1 > m2){
		md = 60+m2-m1;
		h2 -= 1;	
	}
	else md = m2-m1;
	hd = h2-h1;
	int mid = (hd*60+md)/2;
	int h_bias = mid/60;
	int m_bias = mid%60;
		
	if(m1+m_bias >= 60){
		h1 += (m1+m_bias)/60;
		m1 = (m1+m_bias)%60;
	}
	else m1 += m_bias;
	h1 += h_bias;
	if(h1 > 9) cout << h1;
	else cout << "0" << h1;
	cout << ":";
	if(m1 > 9) cout << m1;
	else cout << "0" << m1;
	cout << endl;
	
	return 0;
}
