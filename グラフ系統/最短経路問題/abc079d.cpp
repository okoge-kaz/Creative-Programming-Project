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
// ワーシャルフロイド法 全点間最短距離
// 計算量 O(N^3)
// verify AOJ GRL_1_C 
// 隣接リストでグラフデータを渡しても、内部で隣接行列に変換される

struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
class Warshall_Floyd {
    private:
        int N; vector<vector<ll>>dist; vector<vector<ll>>prev;
        void init(const vector<vector<edge>> &G){
            N = (int)G.size();
            dist.resize(N,vector<ll>(N,INF)); prev.resize(N,vector<ll>(N));
            // 隣接リストから隣接行列に変換
            for(int v=0;v<N;v++){
                for(edge e:G[v]){
                    chmin(dist[e.from][e.to],e.w);
                }
                chmin(dist[v][v],0LL);
            }
            // 初期化
            for(int i=0;i<N;i++) for(int j=0;j<N;j++) prev[i][j] = i;
            // ワーシャルフロイド
            for(int k=0;k<N;k++){
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        // 出発地点i, 終点j, 中継地点k
                        if(dist[i][k]==INF || dist[k][j]==INF) continue;// これをしないと負辺のときにバグる
                        if(chmin(dist[i][j],dist[i][k]+dist[k][j])) prev[i][j] = prev[k][j];
                    }
                }
            }
        }
        void init(const vector<vector<ll>> &G){
            N = (int)G.size();
            dist.resize(N,vector<ll>(N,INF)); prev.resize(N,vector<ll>(N));
            // 隣接リストから隣接行列に変換
            dist = G;
            // 初期化
            for(int i=0;i<N;i++) for(int j=0;j<N;j++) prev[i][j] = i;
            // ワーシャルフロイド
            for(int k=0;k<N;k++){
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        // 出発地点i, 終点j, 中継地点k
                        if(dist[i][k]==INF || dist[k][j]==INF) continue;// これをしないと負辺のときにバグる
                        if(chmin(dist[i][j],dist[i][k]+dist[k][j])) prev[i][j] = prev[k][j];
                    }
                }
            }
        }
    public:
        Warshall_Floyd(const vector<vector<edge>> &G) { init(G); }
        Warshall_Floyd(const vector<vector<ll>> &G) { init(G); }
        ll get_dist(int i, int j){ return dist[i][j]; }
        vector<int> get_path(int s, int g){
            // スタート地点とゴールを入力すると、最短経路を経路復元できる
            vector<int>path;
            for(int cur=g;cur!=s;cur=prev[s][cur]){
                path.push_back(cur);
            }
            path.push_back(s);
            reverse(path.begin(),path.end());
            return path;
        }
        bool is_negative(){
            // 不閉路があるかどうか
            for(int i=0;i<N;i++){
                if(dist[i][i] < 0) return true;
            }
            return false;
        }
};

int main(){
    int H,W; cin >> H >> W;
    vector<vector<ll>>G(10,vector<ll>(10));
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin >> G[i][j];
    Warshall_Floyd data(G);
    ll ans = 0;
    for(int h=0;h<H;h++) for(int w=0;w<W;w++){
        ll a; cin >> a;
        if(a==-1) continue;
        ans += data.get_dist(a,1);
    }
    cout << ans << endl;
}