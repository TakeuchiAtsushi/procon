struct Object {
    // 任意の構造体
    ll x;
    ll y;
    ll depth;
};

queue<Object> q;
vector<string> strv;
ll sy, sx, gy, gx;
int n, m;
vector<vector<ll>> memo;

ll bfs() {
    while (!q.empty()) {
        // キューの先頭の要素を取り出す dequeue(pop)
        Object now = q.front(); q.pop();

        // 停止条件
        // if (now.hoge == target) return ~;  // 探索対象
        if (now.x == gx && now.y == gy) return now.depth;
        
        // BFS
        rep(i, 4){
            ll next_x = now.x + dx[i];
            ll next_y = now.y + dy[i];
            if(next_x < 0 || next_x >= m || next_y <0 || next_y >= n || strv[next_y][next_x] == '#' || memo[next_y][next_x]) continue;
            Object next = {next_x, next_y, now.depth+1};  // 深さ（ステップ数）を一つ足す
            memo[next_y][next_x] = 1;
            q.push(next);
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    strv.resize(n);
    rep(i, n){
        cin >> strv[i];
    }
    memo.resize(n, vector<ll>(m, 0));
    Object start = {sx, sy, 0};
    q.push(start);

    cout << bfs() << endl;
}





struct Object {
    // 任意の構造体
    ll hoge;
    ...
    ll depth;
};

queue<int> q;
Object start = {~~~, 0};  // 深さ 0
q.push(start);  // 初期状態をキューに入れる

int bfs() {
    while (!q.empty()) {
        // キューの先頭の要素を取り出す dequeue(pop)
        Object now = q.front(); q.pop();

        // 停止条件
        // if (now.hoge == target) return ~;  // 探索対象
        if (now.hoge == N) return ~;

        // BFS
        for (int i = 0; i < 次のノード（状態）の数; ++i) {
            Object next = {~~~, depth+1};  // 深さ（ステップ数）を一つ足す
            if (条件) {
                // 条件を満たしたら enqueue(push)
                // 問題により，同じ状態に戻らないようにする処理を書く（無限ループを防ぐ）
                q.push(next);
            }
        }
    }
}




struct Object {
    // 任意の構造体
    ll x;
    ll depth;
};

queue<Object> q;
vector<vec> v;
int N,X,Y;
vector<int> memo;
vector<ll> dist;

void bfs() {
    while (!q.empty()) {
        // キューの先頭の要素を取り出す dequeue(pop)
        Object now = q.front(); q.pop();
        
        // 停止条件
        // if (now.hoge == target) return ~;  // 探索対象
        // if (now.x == gx && now.y == gy) return now.depth;
        
        // BFS
        rep(i, v[now.x].size()){
            ll next_x = v[now.x][i];
            if(memo[next_x]) continue;
            Object next = {next_x, now.depth+1};  // 深さ（ステップ数）を一つ足す
            memo[next_x] = 1;
            dist[next_x] = next.depth;
            q.push(next);
        }
    }
}