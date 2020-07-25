int h, w;
vector<string> cs(550); // 迷路文字列
vector<vec> checked(550, vec(550)); // メモ化
 
void dfs(int x, int y){
  if(x < 0 || x >= w || y < 0 || y >= h || cs[y][x] == '#') return;
  if(checked[y][x]) return;
  
  checked[y][x] = 1;
  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);
}
 
void solve() {
  cin >> h >> w;
  int sx, sy, gx, gy;
  rep(i, h){
    cin >> cs[i];
    rep(j, w){
      if(cs[i][j] == 's') sx = j, sy = i;
      if(cs[i][j] == 'g') gx = j, gy = i;
    }
  }
  
  dfs(sx, sy);
  if(checked[gy][gx]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}








int dfs(int pos, ~~~) {
    // 停止条件
    // 深さに限らず，任意の停止条件を書く
    if (pos == N) return ~~~;

    // pos を進めながら（末端に進みながら）分岐処理
    // 末端まで到達した時それぞれの分岐から値が返される
    // for 文で書ける場合は for 文で実装
    int ret1 = dfs(pos + 1, 分岐 1);
    int ret2 = dfs(pos + 1, 分岐 2);
    int ret3 = dfs(pos + 1, 分岐 3);
    int ret4 = dfs(pos + 1, 分岐 4);
    ...

    // それぞれの分岐からの戻り値の処理を行う関数
    return func(ret1, ret2, ret3, ret4);
}