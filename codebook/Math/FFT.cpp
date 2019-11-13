#define MAXN 262144
#define cplx complex<long double>
const long double PI = acos(-1);
const cplx I(0, 1); 

cplx w[MAXN];

void pre_fft() {
	for (int i = 0; i < MAXN; i++) 
		w[i] = exp(PI * i * 2 / MAXN * I);
}

int reverse_add(int x) {
	for (int l = (1 << 17); (x ^= l) < l; l >>= 1);
	return x;
}

void bit_reverse(cplx a[], int n) {
	for (int i = 0, j = 0; i < n; i++) {
		if (i > j) swap(a[i], a[j]);
		j = reverse_add(j);
	}
}

void fft(cplx a[], int n) {
	bit_reverse(a, n);
	for (int i = 2; i <= n; i <<= 1) {
		int m = i >> 1;
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < m; k++) {
				cplx z = w[n / i * k] * a[j + m + k];
				a[j + m + k] = a[j + k] - z;
				a[j + k] += z;
			}
		}
	}
}

void ifft(cplx a[], int n) {
	fft(a, n);
	vector<cplx> v(n);
	for (int i = 0; i < n; i++) v[i] = a[(n - i) % n] / (long double) n;
	for (int i = 0; i < n; i++) a[i] = v[i];
}

cplx g[MAXN], h[MAXN], x[MAXN];
int ans[MAXN], r;

void init() {
	memset(ans, 0, sizeof(ans));
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	memset(x, 0, sizeof(x));
	r = 0;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	pre_fft();
	string s1, s2;
	while (cin >> s1 >> s2) {
		init();
		for (int i = 0; i < s1.length(); i++) 
			g[s1.length() - i - 1] = cplx(s1[i] - '0', 0);
		for (int i = 0; i < s2.length(); i++)
			h[s2.length() - i - 1] = cplx(s2[i] - '0', 0);
		
		fft(g, MAXN);
		fft(h, MAXN);

		for (int i = 0; i < MAXN; i++)
			x[i] = g[i] * h[i];

		ifft(x, MAXN);

		for (int i = 0; i < MAXN; i++)
			ans[i] = (int)(real(x[i]) + 0.5);
		
		for (int i = 0; i < MAXN; i++) {
			ans[i] = (ans[i] + r);
			r = ans[i] / 10;
			ans[i] %= 10;
		}

		int pos = MAXN - 1;
		while (pos > 0 && ans[pos] == 0) pos--;
		for (int i = pos; i >= 0; i--)
			cout << ans[i];
		cout << '\n';
	}
	return 0;
}
