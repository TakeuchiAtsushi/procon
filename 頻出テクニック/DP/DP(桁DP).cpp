// 以下は13で割ったあまりが5になる個数を求める桁DP
// dp[最大桁数+α][余り]
ll dp[100005][13];

void solve() {
	string S; cin >> S;
    int N = S.size();

    dp[0][0] = 1;
    for(int i=0; i < N; i++){
        int c = 0;
        if(S[i] == '?') c = -1;
        else c = S[i] - '0';

        for(int j=0; j<10; j++){
            if(c != -1 && c != j) continue;
            rep(k, 13){
                dp[i+1][(k*10 + j)%13] += dp[i][k];
            }
        }
        rep(j, 13) dp[i+1][j] %= mod;
    }

    cout << dp[N][5] << endl;
}




string s;
int k;
ll dp[2][105][5]; /* dp[id][i+1][j] : 先頭からi桁目までで0でない数がj個現れるs以下の数の個数。
                                       ただし、id = 0 のとき現時点でsと等しい。
                                       id = 1 のとき現時点でsより小さいことが確定。 */

dp[id || k < lim][i+1][j + (k != 0)] += dp[id][i][j];