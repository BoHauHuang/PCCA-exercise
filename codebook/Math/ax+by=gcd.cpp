pair<int,int> extgcd(int a, int b){
    if (b==0) return {1,0};
    int k = a/b;
    pair<int,int> p = extgcd(b,a-k*b);
    return { p.second, p.first - k*p.second };
}
/*  原始題目求 ax+by=c 的x, y整數解
	正整數解: (g is gcd(a,b))
	x = (x+b/g)*(c/g), x = (x%b/g+b/g)%b/g;
	y = (c-a*x)/b; */
