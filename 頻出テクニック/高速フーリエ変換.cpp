//添字を足した数が同じになるようなものを足した値の配列を返却
typedef complex<ld> com;
typedef vector<com> poly;
poly dft(poly f, bool inverse=false) {
	int n = f.size(); int i, j,k;
	//bit左右反転
	for (i = 0, j = 1; j < n - 1; j++) {
		for (k = n >> 1; k > (i ^= k); k >>= 1);
		if (i > j)swap(f[i], f[j]);
	}
	for (int m = 2; m <= n; m *= 2) {
		com zeta = com(cos(2 * pi / (ld)m), sin(2 * pi / (ld)m));
		if (inverse) {
			zeta = com(cos(2 * pi*(m - 1) / (ld)m), sin(2 * pi*(m - 1) / (ld)m));
		}
		for (i = 0; i < n; i += m) {
			com powzeta = 1;
			for (k = i; k < i + m / 2; k++) {
				com t1 = f[k], t2 = powzeta*f[k + m / 2];
				f[k] = t1 + t2; f[k + m / 2] = t1 - t2;
				powzeta *= zeta;
			}
		}
	}
	if (inverse) {
		for (i = 0; i < n; i++) {
			f[i] /= (ld)n;
		}
	}
	return f;
}
poly multiply(poly g, poly h) {
	int n = 1; int sz = g.size() + h.size();
	while (n <= sz)n *= 2;
	while (g.size() < n) {
		g.push_back(0);
	}
	while (h.size() < n) {
		h.push_back(0);
	}
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff;
	rep(i, n) {
		ff.push_back(gg[i] * hh[i]);
	}
	return dft(ff, true);
}
poly a, b;

void solve() {
  int n; cin >> n;
  rep(i, n) {
		int s, t; cin >> s >> t;
		a.push_back(com(s)); b.push_back(com(t));
	}
	poly z = multiply(a, b);
	cout << 0 << endl;
	rep(i, 2 * n - 1) {
		ll ans = real(z[i]) + eps;
		cout << ans << endl;
	}
  
}