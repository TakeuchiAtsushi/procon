// 一次元
int N; cin >> N; // 配列サイズ
vector<int> a(N);
for (int i = 0; i < N; ++i) cin >> a[i]; // a の入力

// 累積和
vector<ll> s(N+1, 0); // s[0] = 0 になる
for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

// 区間 [left, right) の総和を求める
int left, right;
cin >> left >> right;
cout << s[right] - s[left] << endl;




// 二次元
// 入力: H × W のグリッド
int H, W; cin >> H >> W;
vector<vector<int> > a(H, vector<int>(W));
for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

// 二次元累積和
vector<vector<ll> > s(H+1, vector<ll>(W+1, 0));
for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
        s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

// クエリ [x1, x2) × [y1, y2) の長方形区域の和
int Q; cin >> Q;
for (int q = 0; q < Q; ++q) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
}