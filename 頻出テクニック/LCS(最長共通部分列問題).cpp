#define MAX_N 1000
#define MAX_M 1000

int n, m;
string s, t;

int dp[MAX_N+1][MAX_M+1];

void LCS() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
}

int solve() {
    cin >> n >> m;
    cin >> s >> t;
    LCS();
    cout << dp[n][m] << endl;
}