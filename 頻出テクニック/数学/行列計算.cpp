struct Matrix {
	vector<vector<long long> > val;
	Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
	void init(int n, int m, long long x = 0) { val.assign(n, vector<long long>(m, x)); }
	size_t size() const { return val.size(); }
	inline vector<long long>& operator [] (int i) { return val[i]; }
};

Matrix operator * (Matrix A, Matrix B) {
	Matrix R(A.size(), B[0].size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < B[0].size(); ++j)
			for (int k = 0; k < B.size(); ++k)
				R[i][j] = (R[i][j] + A[i][k] * B[k][j] % mod) % mod;
	return R;
}

Matrix modpow(Matrix A, long long n) {
	Matrix R(A.size(), A.size());
	for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
	while (n > 0) {
		if (n & 1) R = R * A;
		A = A * A;
		n >>= 1;
	}
	return R;
}