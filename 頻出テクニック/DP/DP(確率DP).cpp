int N;
vector<double> p;
double dp[3005][3005];

void solve() {
    cin >> N;
    p.resize(N);
    rep(i, N) cin >> p[i];

    dp[0][0] = 1.0;
    rep(i, N){
        rep(j, N){
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1-p[i]);
        }
    }

    double res=0;
    for(int i=(N+1)/2; i<=N; i++) res += dp[N][i];

    cout << res << endl;
}