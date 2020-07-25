//配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は0を、a,b間の辺が存在しないときはINFを入れておく
//負の閉路があると、d[i][i]が負となる（d[i][i]は負閉路がなければ0になっているはず）
const int MAX_V = 305;
ll d[MAX_V][MAX_V];
void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        // if(d[i][k]==INF || d[k][j] == INF) continue; // 有向グラフの場合
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}