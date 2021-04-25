#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
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
    s = 0;
    cin >> N >> M ;
    // 終点がある場合は、下の最短経路復元用の関数の上のg (=終点)を編集すること
    
    // グラフ
    Graph G(N);
    for(int i=0;i<M;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        --a,--b;
        // 0-indexed --a,--b;
        G[a].push_back(Edge(b,w));
        G[b].push_back(Edge(a,w));
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
    /*
    for(int k=0;k<N;k++){
        ll time = dist[k];// その点に辿り着くまでの最小値
        vector<ll> new_dist(N,INF);
        new_dist[k] = 0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> new_que;
        new_que.push(make_pair(new_dist[k],k));
        // ダイクストラ法の反復を開始
        while(!new_que.empty()){
            // v: 使用済みでない頂点のうち d[v]が最小
            // d: vに対するキー値
            int v = new_que.top().second;
            ll d = new_que.top().first;
            new_que.pop();

            // d > dist[v] は、(d,v)がゴミであることを表す = 最短経路でないもの
            if(d > new_dist[v]) continue;

            // 頂点v を始点とした各辺を緩和
            for(auto e:G[v]){
                if(chemin(new_dist[e.to],new_dist[v] + e.w)){
                    // 更新があるならヒープに新たに挿入
                    new_que.push(make_pair(new_dist[e.to],e.to));
                }
            }
        }
        cout << new_dist[N-1] + time << endl;
    }
    */
   // 上記のようにそれぞれについて求めていては、終わらない。
   // よって逆から考える
    vector<ll> new_dist(N,INF);
    new_dist[N-1] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> new_que;
    new_que.push(make_pair(new_dist[N-1],N-1));
    // ダイクストラ法の反復を開始
    while(!new_que.empty()){
        // v: 使用済みでない頂点のうち d[v]が最小
        // d: vに対するキー値
        int v = new_que.top().second;
        ll d = new_que.top().first;
        new_que.pop();

        // d > dist[v] は、(d,v)がゴミであることを表す = 最短経路でないもの
        if(d > new_dist[v]) continue;

        // 頂点v を始点とした各辺を緩和
        for(auto e:G[v]){
            if(chemin(new_dist[e.to],new_dist[v] + e.w)){
                // 更新があるならヒープに新たに挿入
                new_que.push(make_pair(new_dist[e.to],e.to));
            }
        }
    }
    for(int k=0;k<N;k++){
        cout << dist[k] + new_dist[k] << endl;
    }
}