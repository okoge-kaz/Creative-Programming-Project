#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;
// けんちょん本参考 priority_queueを用いて高速化

struct Edge {
    int to;// 隣接頂点番号
    long long w;// 重み
    Edge(int to, long long w) : to(to) , w(w) {}
};

// 重みつきグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template<class T> bool chemin(T& a, T b){
    if( a > b ){
        a = b;
        return true;
    }
    else return false;
}

// 最短経路を求める場合
vector<ll> get_path(const vector<ll> &prev, ll g){
    // 方針としては、終点g から始点 sまで逆に辿る
    vector<ll> path;
    for(int cur = g; cur != -1;cur = prev[cur]){
        // -1 (= 始点)に戻るまで、prevで逆に戻る
        path.push_back(cur);
    }
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    // 頂点数、辺数、始点
    int N, M, s;
    cin >> N >> M >> s;
    // 終点がある場合は、下の最短経路復元用の関数の上のg (=終点)を編集すること
    
    // グラフ
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        // 0-indexed --a,--b;
        G[a].push_back(Edge(b,w));// 有向グラフなので
    }

    // ダイクストラ法
    vector<ll> dist(N,INF);
    dist[s] = 0;// 始点
    vector<ll> prev(N,-1);// 経路復元
    
    // (d[v], v)のペアを要素としたヒープをつくる
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    // priority_queue は通常、大きい順になるので、greaterによって逆順にしている
    // vector<pair<ll,int>> は逆順にするときに必要な処理:詳細はAPG4b
    que.push(make_pair(dist[s], s));

    // ダイクストラ法の反復を開始
    while(!que.empty()){
        // v: 使用済みでない頂点のうち d[v]が最小
        // d: vに対するキー値
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        // d > dist[v] は、(d,v)がゴミであることを表す = 最短経路でないもの
        if(d > dist[v]) continue;

        // 頂点v を始点とした各辺を緩和
        for(auto e:G[v]){
            if(chemin(dist[e.to],dist[v] + e.w)){
                // 更新があるならヒープに新たに挿入
                que.push(make_pair(dist[e.to],e.to));
                // 経路復元用
                prev[e.to] = v;// vを通って e.toに辿り着いた
            }
        }
    }

    // 結果出力
    for(int v=0;v<N;v++){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }

    // 最短経路復元
    // ゴールをg とする。
    ll g;
    auto ans = get_path(prev, g);// ans は vector 
    // prev は前に定義した vector , gはgoal
}









// priority_queueの工夫なし
// 素朴な解法

struct Edge {
    int to;// 隣接頂点番号
    long long w;// 重み
    Edge(int to, long long w) : to(to) , w(w) {}
};

// 重みつきグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template<class T> bool chemin(T& a, T b){
    if( a > b ){
        a = b;
        return true;
    }
    else return false;
}

int main(){
    // 頂点数、辺数、始点
    int N, M, s;
    cin >> N >> M >> s;
    // グラフ
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        // 0-indexed --a,--b;
        G[a].push_back(Edge(b,w));// 有向グラフなので
    }

    // ダイクストラ法
    vector<bool> used(N, false);
    vector<ll> dist(N,INF);
    dist[s] = 0;// 始点
    for(int iter=0;iter<N;iter++){
        // 使用済みでない頂点のうち、dist値が最小の頂点を探す
        ll min_dist = INF;
        int min_v = -1;
        for(int v=0;v<N;v++){
            if(!used[v] && dist[v] < min_dist){
                // 使用済みでなく、もっとも短い距離
                min_dist = dist[v];
                min_v = v;
            }
        }

        // もしそのような頂点が見つからなけらば終了する
        if(min_v == -1) break;

        // min_v を始点とした各辺を緩和する
        for(auto e: G[min_v]){
            chemin(dist[e.to], dist[min_v] + e.w);
            // dist[e.to] = min(dist[e.to], dist[min_v] + e.w);と同じ
        }
        used[min_v] = true;// min_v を使用済みにする
    }

    // 結果出力
    for(int v=0;v<N;v++){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}