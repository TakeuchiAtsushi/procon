// 負の閉路がある場合は使用不可
const int MAX_V=100005;

struct edge {
    int to;
    ll cost;
};

// <最短距離, 頂点の番号>
// using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];
int pre[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    fill(pre, pre+V, -1);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pre[e.to] = v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

// 経路復元
vector<int> get_path(int t){ //頂点tへの最短路
    vector<int> path;
    for(; t != -1;t=pre[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    // 頂点の個数
    cin >> V;
    // 辺の個数
    int E;
    cin >> E;
    for (int i=0; i<E; ++i) {
        // aに繋がる頂点b,距離c
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b, c};
        G[a].push_back(e);
        // 有向の場合は片方のみ
        e = {a, c};
        G[b].push_back(e);
    }
    dijkstra(0);
    for (int i=0; i<V; ++i) {
        if(d[i] != max_n)
            cout << "0から" << i << "までのコスト: " << d[i] << endl;
    }
}