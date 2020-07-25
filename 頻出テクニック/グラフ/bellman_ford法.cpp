// 二点間（頂点Sから頂点G）までの最短経路を求める場合のbellman_ford
// 負の閉路検出が可能
#define MAX_V 1000

struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};

int V; //頂点の数
int side; //辺の数
int S; //始点
int G; //終点
int d[MAX_V]; //始点からそこまで行くのにかかるコスト
vector<edge> edges; //移動の情報を保存する

bool bellman_ford() {
    fill(d, d+V, INF_N); //すべての頂点をINF_Nにする
    d[S] = 0; //始点を0にする

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (int)edges.size(); j++) {

            struct edge e = edges[j];

            if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
                d[e.to] = d[e.from] + e.cost;
                if (i == V-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    return true; // V回目にも更新があるなら負の閉路が存在
                } 
            }
        }
    }
    return false;
}

void solve(){
    cin >> V; 
    cin >> side;
    cin >> S;
    cin >> G;

    for (int i = 0; i < side; i++) {
        struct edge add;
        cin >> add.from;
        cin >> add.to;
        cin >> add.cost;
        edges.push_back(add);
    }

    fill(d, d+V, INF_N); //すべての頂点をINF_Nにする
    d[S] = 0; //始点を0にする

    if(bellman_ford()){
      cout << "負のループあり" << endl;
    }else{
      cout << "\n頂点" << S << "から頂点" << G << "まで移動するのにかかるコストの最小は" << d[G] << endl;
    }
}