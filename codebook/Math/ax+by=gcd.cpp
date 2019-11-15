pair<int,int> extgcd(int a, int b){
    if (b==0) return {1,0};
    int k = a/b;
    pair<int,int> p = extgcd(b,a-k*b);
    return { p.second, p.first - k*p.second };
}
/* �D�Xax+by=c�� x, y����Ƹ�
	�ॿ���: g is gcd(a,b)
	x = (x+b/g)*(c/g), x = (x%b/g+b/g)%b/g;
	y = (c-a*x)/b; */
