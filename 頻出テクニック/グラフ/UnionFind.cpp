struct uf {
private:
  vector<int> par, ran,sz;
public:
  uf(int n) {
    par.resize(n, 0);
    ran.resize(n, 0);
    sz.resize(n, 1);
    rep(i, n) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)return;
    if (ran[x] < ran[y]) {
      par[x] = y; sz[y] += sz[x];
    }
    else {
      par[y] = x; sz[x] += sz[y];
      if (ran[x] == ran[y])ran[x]++;
    }
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int num(int x) { return sz[find(x)]; }
};
 
// vector<int> b[1 << 17];
// void solve() {
//   int n, m, k; cin >> n >> m >> k;
//   uf u(n);
//   rep(i, m) {
//     int s, t; cin >> s >> t; s--; t--;
//     u.unite(s, t);
//     b[s].push_back(t);
//     b[t].push_back(s);
//   }
//   rep(i, k) {
//     int s, t; cin >> s >> t; s--; t--;
//     b[s].push_back(t);
//     b[t].push_back(s);
//   }
//   vector<int> ans(n);
//   rep(i, n) {
//     int cnt = u.num(i);
//     for (int to : b[i]) {
//       if (u.same(i, to))cnt--;
//     }
//     ans[i] = cnt-1;
//   }
//   rep(i, n) {
//     if (i > 0)cout << " ";
//     cout << ans[i];
//   }
//   cout << endl;
// }