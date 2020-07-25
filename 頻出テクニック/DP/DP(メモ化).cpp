// DFS的なメモ化DP
int N, M;
vector<vec> G;
int dp[100005];

int rec(int v){
    if(dp[v] != -1) return dp[v]; // 既に更新済み

    int res=0;
    for(auto nv: G[v]){
        res = max(res, rec(nv)+1);
    }

    return dp[v] = res; // メモしながらreturn
}

void solve() {
    cin >> N >> M;
    G.resize(N);

    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    memset(dp, -1, sizeof(dp));
    int res = 0;
    rep(i, N) res = max(res, rec(i));

    cout << res << endl;
}





// BFS的なメモ化DP
int N, M;
queue<int> q;
vector<vec> G;
vec deg;
int dp[100005];

void solve() {
    cin >> N >> M;
    G.resize(N);
    deg.resize(N, 0);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        deg[b]++;
    }

    memset(dp, 0, sizeof(dp));
    rep(i, N) if(deg[i] == 0) q.push(i);

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv: G[v]){
            deg[nv]--;
            if(deg[nv] == 0){
                q.push(nv);
                dp[nv] = max(dp[nv], dp[v]+1);
            }
        }
    }

    int res=0;
    rep(i, N) res = max(res, dp[i]);
    cout << res << endl;
}