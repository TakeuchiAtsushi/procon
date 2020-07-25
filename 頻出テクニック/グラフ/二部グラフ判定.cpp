// 二部グラフ判定を行うコード
// グラフが連結ならば以下のコード一度で二部グラフ判定が可能。
// 連結でない場合はすべての頂点において探索する必要があることに注意
using Graph = vector<vector<ll>>;
int colors[100005];
bool is_bipartite_graph(const Graph &graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}