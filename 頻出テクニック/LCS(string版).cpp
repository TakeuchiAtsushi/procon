string LCS(string s, string t) {
    int n = s.size(), m = t.size();
    string dp[n+5][m+5];
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j];
                dp[i+1][j+1].push_back(s[i]);
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}