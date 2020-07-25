int N;
double dp[305][305][305];
int a[305];

double rec(int i, int j, int k){
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;

    double res=0.0;
    if(i > 0) res += rec(i-1, j, k)*i;
    if(j > 0) res += rec(i+1, j-1, k)*j;
    if(k > 0) res += rec(i, j+1, k-1)*k;
    res += N;
    res *= 1.0 / (i + j + k);

    return dp[i][j][k] = res;
}

void solve() {
    cin >> N;
    rep(i, N) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    int one=0, two=0, three=0;
    rep(i, N){
        if(a[i]==1) one++;
        if(a[i]==2) two++;
        if(a[i]==3) three++;
    }

    cout << rec(one, two, three) << endl;
}