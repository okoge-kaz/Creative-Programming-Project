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
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// ベルマンフォード法
// 負辺の検出をすることができるが、計算量はO(V+E)となる

struct Edge {
    int to;// 隣接頂点番号
    long long w;// 重み
    Edge(int to, long long w) : to(to) , w(w) {}
};
// ベルマンフォード法のときは、こちらの形の方が都合が良い
struct edge {
    int from;
    int to;
    ll w;
    edge (int from, int to, ll w): from(from), to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

int main(){
    // 頂点数、辺数、始点
    int N, M, s;
    cin >> N >> M >> s;
    
    // グラフ
    Graph G(N);
    vector<edge>edges;
    for(int i=0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        // 0-indexed --a,--b;
        edges.push_back(edge(a,b,w));// 有向グラフ
        G[a].push_back(Edge(b,w));// 有向グラフなので
    }
    // ベルマンフォード法では、vector<vector<Edge>>Gをそもそも使っていない
    vector<ll> dist(N,INF);
    dist[s] = 0;// 始点
    bool negative = false;
    for(int j=0;j<N;j++){
        for(int i=0;i<M;i++){
            edge e = edges[i];
            if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.w ){
                chmin(dist[e.to],dist[e.from]+e.w);
                if(j==N-1) negative = true;
            }
        }
    }

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    // 結果出力
    for(int v=0;v<N;v++){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
