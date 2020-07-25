// トポロジカルソートする
// orderをreverseすることでトポロジカルソートを得る
vector<vec> G;
void rec(int v, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, seen, order);
    }
    order.push_back(v);
}


// 探索
//     vector<bool> seen(N, 0); // 初期状態では全ノードが未訪問
//     vector<int> order; // トポロジカルソート順
//     for (int v = 0; v < N; ++v) {
//         if (seen[v]) continue; // 既に訪問済みなら探索しない
//         rec(v, seen, order);
//     }
//     reverse(order.begin(), order.end()); // 逆順に